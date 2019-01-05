#include "mcc_generated_files/mcc.h"
#include "messages.h"
#include "main.h"
#include "master.h"
#include "slave.h"
#include <stdarg.h>

/*
 * Columns refer to columns on the front panel, and are numbers 0..(NUM_CHANNELS-1)
 * Channels refer to remote stations, and are numbered 1..NUM_CHANNELS
 */

uint8_t g_current_column = 0;
uint8_t g_config = 0;
uint8_t g_prev_config = 0;
uint8_t g_mode;         // 0 = slave, 1 = master
uint8_t g_my_address;   // My address on the messaging bus
uint8_t g_num_channels; // Number of channels, if in master mode
uint8_t g_num_columns;  // Number of button columns on master panel
uint8_t g_last_poll;    // Last slave the master sent a POLL to
uint16_t g_poll_rate;    // How often we poll the slave
uint8_t g_next_poll;
uint16_t g_poll_counter;

/* LED array - 0 is off, 1 is on */
uint8_t g_leds[NUM_ROWS][MAX_COLUMNS];
/* Buttons - 0 is pressed, 1 is not pressed */
uint8_t g_buttons[NUM_ROWS][MAX_COLUMNS];
uint8_t g_prev_buttons[NUM_ROWS][MAX_COLUMNS];
struct channel g_channel[MAX_CHANNELS];

void update_LEDS(void);
void update_buttons(void);
void handle_config_change(void);
void print_config(void);
void set_master_mode(void);
void set_slave_mode(void);
void read_config(void);
void main_loop(void);

/**
 * ISR for blinking LEDs
 * Called every 500 ms
 * Usage: Master and slave
 * 
 * Any channel that is in STANDBY will have its LED toggled
 */
void blink_isr(void) {
    uint8_t i;
    
    if (g_mode == MODE_MASTER) {
        for (i = 0; i < g_num_channels; i++) {
            if (g_channel[i].state == STATE_STANDBY) {
                g_leds[ROW_STANDBY][i] = ~(g_leds[ROW_STANDBY][i]);
            }
        }
    } else {  
        if (g_slave_state == STATE_STANDBY) {
            if (LED0_LAT == 0) {
                LED0_SetHigh();
            } else {
                LED0_SetLow();
            }
        }
    }
    
    /* Recheck the config dip switches while we're here */
    read_config();
    
    if (g_config != g_prev_config) {
        handle_config_change();
    }
}

/**
 * ISR for multiplex of LEDs and Buttons
 * Called every 3 ms
 * Usage:  Master mode only
 * 
 * Increments the column number, disables all columns,
 * sets new LED values, enables the new column, and 
 * checks for button presses on that column.
 * 
 */
void multiplex_isr(void) {
    uint8_t col_select;
    
    if (g_mode == MODE_SLAVE) {
        COL0_SetDigitalOutput();
        COL0_SetLow();
        return;
    }
    
    ++g_current_column;
    if (g_current_column >= g_num_columns) {
        g_current_column = 0;
    }

    if (g_current_column < 8) {
        // Port A
        col_select = (~(1 << g_current_column));
        TRISA = 0xff;
        TRISC = 0xff; // Tri-state all columns
        update_LEDS(); // Set new values
        TRISA = col_select; // Set new column to output
    } else {
        // Port C
        col_select = (~(1 << (g_current_column - 8)));
        TRISA = 0xff;
        TRISC = 0xff;
        update_LEDS();
        TRISC = col_select;
    }

    update_buttons();
    
    ++g_poll_counter;
    if (g_poll_counter >= g_poll_rate) {
        g_poll_counter = 0;
        ++g_next_poll;
        if (g_next_poll > g_num_channels) {
            g_next_poll = 1;
        }
    }
}

/**
 * Update LED outputs
 * Called by the multiplex ISR
 * Usage: Master mode only
 * 
 */
void update_LEDS(void) {
    if (g_leds[ROW_STANDBY][g_current_column]) {
        LED0_SetHigh();
    } else {
        LED0_SetLow();
    }
    if (g_leds[ROW_GO][g_current_column]) {
        LED1_SetHigh();
    } else {
        LED1_SetLow();
    }
    if (g_leds[ROW_SELECT][g_current_column]) {
        LED2_SetHigh();
    } else {
        LED2_SetLow();
    }    
}

/**
 * Reads button inputs
 * Called by the multiplex ISR
 * Usage: Master only
 */
void update_buttons() {
    g_buttons[0][g_current_column] = BTN0_GetValue();
    g_buttons[1][g_current_column] = BTN1_GetValue();
    g_buttons[2][g_current_column] = BTN2_GetValue();
}

/*
                         Main application
 */
void main(void)
{
    uint8_t r;
    uint8_t c;
    uint8_t i;
        
    // Initialize the device
    SYSTEM_Initialize(); 
    message_init();
    
    // All columns LOW and Tri-State
    LATA = 0;
    TRISA = 0xff;
    LATC = 0;
    TRISC = 0xff;
    
    /* Read initial config */
    read_config();
    handle_config_change();
       
    for (r=0; r<NUM_ROWS; r++) {
        for (c=0; c<MAX_COLUMNS; c++) {
            g_leds[r][c] = LED_OFF;
            g_buttons[r][c] = 1;
            g_prev_buttons[r][c] = 1;
        }
    }
    
    for (i=0; i<MAX_CHANNELS; i++) {
        g_channel[i].state = STATE_IDLE;
        g_channel[i].present = 0;
        g_channel[i].selected = 0;
    }
    
    /* Polling */
    g_last_poll = 0;
    g_next_poll = 1;
    g_poll_counter = 0;
#ifdef DEBUG
    /* In debug mode, poll a slave every 333 multiplex ticks, about 1 sec */
    g_poll_rate = 333;
#else
    /* In normal mode, poll a slave every 4 multiplex ticks, about 12 ms */
    g_poll_rate = 4;
#endif

    
    
    TMR0_SetInterruptHandler(multiplex_isr);
    TMR1_SetInterruptHandler(blink_isr);
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();
   
    DBG_PRINT("Started.\r\n");
    print_config();
    
    while (1) {
        /* Call the global loop routine */
        main_loop();
        /* Call the master or slave loop routine */
        if (g_mode == MODE_MASTER) {
            master_loop();
        } else {
            slave_loop();
        } 
    }
}


void handle_config_change() {
    DBG_PRINT("Config change, ");
    /* 
     * High bit is mode: 0=slave, 1=master 
     * In master mode the lower three bits indicate how many channels to 
     * expect on the line and how many columns of buttons there are.
     * In slave mode the lower three bits indicate the channel's address
     * In both cases 1 is added to the value of the switch, so number of
     * channels can be 1-8 and channel address can be 1-8.
     */
    
    if (g_config & 0x8) {
        /* Master */
        g_num_channels = (g_config & 0x07) + 1;
        g_num_columns = g_num_channels + 2;
        g_my_address = MSG_MASTER;
    } else {
        /* Slave */
        g_my_address = (g_config & 0x07) + 1;
    }
        
    if (g_config & 0x8) {
        set_master_mode();
    } else {
        set_slave_mode();
    }
    
    print_config();
    g_prev_config = g_config;
}

void print_config(void) {
    if (g_mode == MODE_MASTER) {
        printf("Master mode, %d channels\r\n", g_num_channels);
    } else {
        printf("Slave mode, channel %d\r\n", g_my_address);
    }    
}

void set_master_mode() {
    g_mode = MODE_MASTER;
    TMR0_StartTimer();
    master_do_discovery();
}

void set_slave_mode() {
    g_mode = MODE_SLAVE;
    /* Slaves don't need the multiplex timer */
    TMR0_StopTimer();
    /* Set COL0 low as a ground for the slave buttons and LEDs */
    LATA = 0;
    TRISA = 0xfe;
    LATC = 0;
    TRISC = 0xff;
    printf("Driving Col0 Low\r\n");
    COL0_SetDigitalOutput();
    COL0_SetLow();
}

void read_config(void) {
    g_config = CFG0_GetValue();
    g_config |= CFG1_GetValue() << 1;
    g_config |= CFG2_GetValue() << 2;
    g_config |= CFG3_GetValue() << 3;
}

void dbg_print(const char *str) {
#if DEBUG
    const char *p = str;
    while (*p != '\0') {
        EUSART2_Write(*p);
        ++p;
    }
#endif
}

void dbg_putch(const char c) {
#if DEBUG
    EUSART2_Write(c);
#endif
}

/**
 * Perform loop functions common to master and slave
 */
void main_loop() {
    queue_ib_msgs();
}