#include "main.h"
#include "slave.h"
#include "messages.h"

static void slave_handle_message(struct message *msg);
static void slave_handle_button_press(void);

static uint8_t curr_button;
static uint8_t prev_button;
uint8_t g_slave_state;

void slave_loop(void) {
    /* Check for a button press */
    // Look for high to low transition
    curr_button = BTN0_GetValue();
    if ((curr_button == 0) && (prev_button == 1)) {
        // Button press detected
        __delay_ms(DEBOUNCE_MSEC);
        if (curr_button == 0) {
            slave_handle_button_press();
            prev_button = curr_button;
        }
    } else if ((curr_button == 1) && (prev_button == 0)) {
        // Rising edge, just update prev_buttons
        prev_button = curr_button;
    }
    
    /* Check for an incoming message */   
    if (message_avail()) {
        struct message *msg = message_recv();
        slave_handle_message(msg); 
    }
}

static void slave_handle_message(struct message *msg) {
    if (msg->from != MSG_MASTER) {
        return;
    }
    if (msg->to != g_my_address) {
        return;
    }
    switch (msg->msg_type) {
        case MSG_IDLE:
            LED0_SetLow();
            LED1_SetLow();
            message_send(g_my_address, MSG_MASTER, MSG_IDLE_ACK);
            g_slave_state = STATE_IDLE;
            break;
        case MSG_STANDBY:
            LED0_SetLow(); // The Blink ISR will blink this
            LED1_SetLow();
            message_send(g_my_address, MSG_MASTER, MSG_STANDBY_ACK);
            g_slave_state = STATE_STANDBY;
            break;
        case MSG_GO:
            LED0_SetLow();
            LED1_SetHigh();
            message_send(g_my_address, MSG_MASTER, MSG_GO_ACK);
            g_slave_state = STATE_GO;
            break;
        case MSG_READY_ACK:
            LED0_SetHigh();
            LED1_SetLow();
            g_slave_state = STATE_READY;
            break;
        case MSG_POLL:
            message_ob_process();
        default:
            break;           
    }
}

static void slave_handle_button_press() {
    message_send(g_my_address, MSG_MASTER, MSG_READY);
}
