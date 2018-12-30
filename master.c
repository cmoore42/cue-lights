#include "main.h"
#include "master.h"
#include "messages.h"

static void master_handle_message(struct message *msg);
static void master_handle_button_press(uint8_t r, uint8_t c);
static void master_set_state(uint8_t chan, uint8_t state);

void master_loop(void) {
    int r;
    int c;
    
    /* Check all buttons for a press */
    for (r = 0; r < NUM_ROWS; r++) {
        for (c = 0; c < g_num_columns; c++) {
            // Look for high to low transition
            if ((g_buttons[r][c] == 0) && (g_prev_buttons[r][c] == 1)) {
                // Button press detected
                __delay_ms(DEBOUNCE_MSEC);
                if (g_buttons[r][c] == 0) {
                    master_handle_button_press(r, c);
                    g_prev_buttons[r][c] = g_buttons[r][c];
                }
            } else if ((g_buttons[r][c] == 1) && (g_prev_buttons[r][c] == 0)) {
                // Rising edge, just update prev_buttons
                g_prev_buttons[r][c] = g_buttons[r][c];
            }
        }
    }
    
    /* Check for incoming messages to process */
    if (message_avail()) {
        struct message *msg = message_recv();
        master_handle_message(msg);      
    }
    
    /* Process outgoing messages */
    message_ob_process();
    
    /*
     * Send a POLL message to a slave
     * g_next_poll gets incremented by the multiplex ISR
     * This results in a POLL message being sent periodically to each slave
     * The slave only transmits back in response to a POLL
     */
 
    if (g_next_poll != g_last_poll) {
        message_send(MSG_MASTER, g_next_poll, MSG_POLL);
        g_last_poll = g_next_poll;
    }
}

static void master_handle_button_press(uint8_t r, uint8_t c) {
    uint8_t i;
    
    dbg_print("Button ");
    dbg_putch('0'+r);
    dbg_print(", ");
    if (c > 9) {
        dbg_putch('1');
        dbg_putch('0' + c - 10);
    } else {
        dbg_putch('0' + c);
    }
    dbg_print("\r\n");

    if (c == g_num_columns-1) {
        // Rightmost column
        switch(r) {
            case ROW_STANDBY:
                // Select All
                dbg_print("Select All\r\n");
                for (i=0; i<g_num_channels; i++) {
                    g_channel[i].selected = 1;
                    g_leds[ROW_SELECT][i] = LED_ON;
                }
                break;
            case ROW_GO:
                dbg_print("Select None\r\n");
                // Select None
                for (i=0; i<g_num_channels; i++) {
                    g_channel[i].selected = 0;
                    g_leds[ROW_SELECT][i] = LED_OFF;
                }
                break;
            case ROW_SELECT:
                dbg_print("Clear All\r\n");
                // Clear All
                for (i=0; i<g_num_channels; i++) {
                    message_send(MSG_MASTER, i+1, MSG_IDLE);
                }
                break;
        }
    } else if (c == g_num_columns-2) {
        // Second to right column
        switch(r) {
            case ROW_STANDBY:
                dbg_print("Standby Selected\r\n");
                // Standby Selected
                for (i=0; i<g_num_channels; i++) {
                    if (g_channel[i].selected) {
                        message_send(MSG_MASTER, i+1, MSG_STANDBY);
                    }
                }
                break;
            case ROW_GO:
                dbg_print("Go Selected\r\n");
                // Go Selected
                for (i=0; i<g_num_channels; i++) {
                    if (g_channel[i].selected) {
                        message_send(MSG_MASTER, i+1, MSG_GO);
                    }
                }
                break;
            case ROW_SELECT:
                dbg_print("Clear Selected\r\n");
                // Clear Selected
                for (i=0; i<g_num_channels; i++) {
                    if (g_channel[i].selected) {
                        message_send(MSG_MASTER, i+1, MSG_IDLE);
                    }
                }
                break;
        }       
    } else {
        // One of the channel buttons
        int channel = c+1;
        dbg_print("Channel ");
        dbg_putch('0' + channel);
        switch (r) {
            case ROW_STANDBY:               
                // Standby
                if ((g_channel[c].state == STATE_IDLE) ||
                    (g_channel[c].state == STATE_GO)) {
                    dbg_print("Idle -> Standby\r\n");
                    message_send(MSG_MASTER, channel, MSG_STANDBY);
                } else {
                    dbg_print("Standby -> Idle\r\n");
                    message_send(MSG_MASTER, channel, MSG_IDLE);
                }
                break;
            case ROW_GO:                // Go
                if (g_channel[c].state == STATE_GO) {
                    dbg_print("Go -> Idle\r\n");
                    message_send(MSG_MASTER, channel, MSG_IDLE);
                } else {
                    dbg_print("Idle -> Go\r\n:");
                    message_send(MSG_MASTER, channel, MSG_GO);
                }
                break;
            case ROW_SELECT:
                // Select
                g_channel[c].selected = !(g_channel[c].selected);
                g_leds[ROW_SELECT][c] = g_channel[c].selected;
                if (g_channel[c].selected) {
                    dbg_print("Selected\r\n");
                } else {
                    dbg_print("Unselected\r\n");
                }
                break;
        }       
    }
}

/**
 * Process a message from a slave
 * Usage: Master mode only
 * 
 * @param from the channel ID of the slave
 * @param to recipient - should be MSG_MASTER
 * @param msg the message received
 */
static void master_handle_message(struct message *msg) {
    
    dbg_putch(msg->msg_type + '0');
    dbg_print("<=");
    dbg_putch(msg->from + '0');
    dbg_print("\r\n");
    if (msg->to != MSG_MASTER) {
        return;
    }
    if (msg->from == MSG_MASTER) {
        return;
    }
    if (msg->from > g_num_channels) {
        return;
    }
    
    switch(msg->msg_type) {
        case MSG_READY:
            message_send(MSG_MASTER, msg->from, MSG_READY_ACK);
            if (g_channel[msg->from-1].state == STATE_STANDBY) {
                master_set_state(msg->from, STATE_READY);
            }
            break;
        case MSG_IDLE_ACK:
            master_set_state(msg->from, STATE_IDLE);
            break;
        case MSG_STANDBY_ACK:
            master_set_state(msg->from, STATE_STANDBY);
            break;
        case MSG_GO_ACK:
            master_set_state(msg->from, STATE_GO);
            break;
        case MSG_PRESENCE:
            dbg_print("Channel ");
            dbg_putch(msg->from + '0');
            dbg_print(" present\r\n");
            break;
    }
}

/**
 * Update the state of a channel
 * Usage: Master mode only
 * 
 * @param chan - channel to update
 * @param state - new state for channel
 */
static void master_set_state(uint8_t chan, uint8_t state) {
    uint8_t column;
    
    column = chan-1;
    
#ifdef DEBUG
    dbg_putch('C');
    dbg_putch(chan + '0');
    dbg_putch('S');
    dbg_putch(state + '0');
    dbg_print("\r\n");
#else
    /*
    EUSART2_Write('C');
    EUSART2_Write(chan + '0');
    EUSART2_Write('S');
    EUSART2_Write(state + '0');
    EUSART2_Write('\r');
    EUSART2_Write('\n');
     */
#endif
    g_channel[column].state = state;
    switch (state) {
        case STATE_IDLE:
            g_leds[ROW_STANDBY][column] = LED_OFF;
            g_leds[ROW_GO][column] = LED_OFF;
            break;
        case STATE_STANDBY:
            /* Blink the Standby button */
            g_leds[ROW_GO][column] = LED_OFF;
            break;
        case STATE_READY:
            g_leds[ROW_STANDBY][column] = LED_ON;
            g_leds[ROW_GO][column] = LED_OFF;
            break;
        case STATE_GO:
            g_leds[ROW_STANDBY][column] = LED_OFF;
            g_leds[ROW_GO][column] = LED_ON;
            break;
    }
}

void master_do_discovery(void) {
    /* Ultimately this should query each channel to see if it responds. 
     * for now we'll just pretend we found all the channels.
     */
    
    uint8_t i;
    
    for (i=0; i<g_num_channels; i++) {
        g_channel[i].present = 1;
    }
}