#ifndef MAIN_H
#define	MAIN_H

#include "mcc_generated_files/mcc.h"
#include <xc.h> 

#ifdef	__cplusplus
extern "C" {
#endif
    
void dbg_print(const char *str);
void dbg_putch(const char c);
    
#ifdef DEBUG
#define DEBUG_TEST 1
#else 
#define DEBUG_TEST 0
#endif
    
#define LED_ON 1
#define LED_OFF 0

#define MODE_SLAVE 0
#define MODE_MASTER 1
    
#define ROW_STANDBY 0
#define ROW_GO 1
#define ROW_SELECT 2

#define MAX_CHANNELS 14
#define MAX_COLUMNS (MAX_CHANNELS + 2)
#define NUM_ROWS 3
#define DEBOUNCE_MSEC 10

#define STATE_IDLE 0
#define STATE_STANDBY 1
#define STATE_READY 2
#define STATE_GO 3   

struct channel {
    uint8_t state;
    uint8_t present;
    uint8_t selected;
};

extern uint8_t g_current_column;
extern uint8_t g_config;
extern uint8_t g_prev_config;
extern uint8_t g_mode;         // 0 = slave, 1 = master
extern uint8_t g_my_address;   // Channel ID, if in slave mode
extern uint8_t g_num_channels; // Number of channels, if in master mode
extern uint8_t g_num_columns;  // Number of button columns on master panel
extern uint16_t g_poll_rate;    // How often we poll the slaves
extern uint8_t g_last_poll;    // Address of the last channel we sent a MSG_POLL to
extern uint8_t g_next_poll;
extern uint16_t g_poll_counter;

/* LED array - 0 is off, 1 is on */
extern uint8_t g_leds[NUM_ROWS][MAX_COLUMNS];
/* Buttons - 0 is pressed, 1 is not pressed */
extern uint8_t g_buttons[NUM_ROWS][MAX_COLUMNS];
extern uint8_t g_prev_buttons[NUM_ROWS][MAX_COLUMNS];
extern struct channel g_channel[MAX_CHANNELS];

#ifdef	__cplusplus
}
#endif

#endif	/* MAIN_H */

