#include "mcc_generated_files/mcc.h"
#include "main.h"
#include "messages.h"
#include "slave.h"

uint8_t ob_pi;
volatile uint8_t ob_ci;
volatile uint8_t ib_pi;
uint8_t ib_ci;
struct message outbound_q[QSIZE];
struct message inbound_q[QSIZE];

/*
 * NOTE:  There is no protection for overrunning the buffer.  If rx_offset_in
 * ever wraps all the way around and runs into rx_offset_out Bad Things will 
 * happen.
 */
#define RX_BUFSIZE 128
uint8_t recv_buffer[RX_BUFSIZE];
#define RX_OFFSET_MASK (RX_BUFSIZE - 1)
uint8_t rx_offset_in;   // The offset at which we will insert the next byte
uint8_t rx_offset_out;  // The offset from which we will remove the next byte

static void xmit_msg(struct message *msg);
void message_rx_isr(void);
static void RX_Mode(void);
static void TX_Mode(void);
static void queue_ib_msg(uint8_t offset);

/**
 * Initialize the messaging interface.
 * Used by: Master and slave
 * 
 */
void message_init(void) {
    ob_pi = 0;
    ob_ci = 0;
    ib_pi = 0;
    ib_ci = 0;
    rx_offset_in = 0;
    rx_offset_out = 0;
    
    /* Set up our own receive ISR */
    EUSART1_SetRxInterruptHandler(message_rx_isr);
    
    /* Normal state is receiver enabled, transmitter disabled */
    RX_Mode();
}

/**
 * Add a message to the outbound message queue.
 * 
 * @param from sender's address
 * @param to receiver's address
 * @param msg message to be sent
 * 
 * If the outbound queue is full this will return with no
 * indication of the failure.
 */
void message_send(uint8_t from, uint8_t to, uint8_t msg) {
    if (ob_pi == ((ob_ci-1) & IDX_MASK)) {
        /* Queue full */
        return;
    }
    
    // (("message_send: put PI %d\r\n", ob_pi));
    outbound_q[ob_pi].from = from;
    outbound_q[ob_pi].to = to;
    outbound_q[ob_pi].msg_type = msg;
    ob_pi = ((ob_pi + 1) & IDX_MASK);
    
}

/**
 * Return the next message from the inbound message queue
 * Used by:  Master and slave
 * 
 * The message is removed from the queue.
 * 
 * @return pointer to next available message, or NULL if the queue is empty
 */
struct message *message_recv(void) {
    struct message *result;
    
    if (ib_pi == ib_ci) {
        /* Queue empty */
        return NULL;
    }
    
    result = &(inbound_q[ib_ci]);
    ib_ci = ((ib_ci + 1) & IDX_MASK);
    return result;
}

/**
 * Check status of inbound message queue
 * @return 0 if the inbound queue is empty, 1 if it is not empty
 */
uint8_t message_avail(void) {
    if (ib_pi == ib_ci) {
        return 0;
    } else {
        return 1;
    }
}

/**
 * Process any outgoing messages from the queue
 * Used by: Master and slave
 * 
 * Called in the main loop by the Master.
 * Called by the Slave when it receives a MSG_POLL message.
 * 
 * If there are any messages in the outbound queue they
 * are removed from the queue and transmitted over the
 * outgoing message interface.
 * 
 * In slave mode a MSG_PRESENCE message will be sent after
 * the last message in the queue.
 * 
 */
void message_ob_process(void) {
    struct message *msg;
    struct message reply;
    
    while (ob_pi != ob_ci) {
        msg = &(outbound_q[ob_ci]);
        xmit_msg(msg);
        ob_ci = ((ob_ci + 1) & IDX_MASK);
    }
    
    if (g_mode == MODE_SLAVE) {
        reply.from = g_my_address;
        reply.to = MSG_MASTER;
        switch(g_slave_state) {
            case STATE_IDLE:
                reply.msg_type = MSG_INSTATE_IDLE;
                break;
            case STATE_STANDBY:
                reply.msg_type = MSG_INSTATE_STANDBY;
                break;
            case STATE_READY:
                reply.msg_type = MSG_INSTATE_READY;
                break;
            case STATE_GO:
                reply.msg_type = MSG_INSTATE_GO;
                break;
        }
        xmit_msg(&reply);
    }
}

/**
 * Put a message on the wire
 * Used by: Master and slave
 * 
 * Turn on the transmitter
 * Send the message
 * Wait for the transmitter to empty
 * Turn off the transmitter
 * 
 * @param msg pointer to the message to be sent
 */
static void xmit_msg(struct message *msg) {
    TX_Mode();
    EUSART1_Write(MSG_SOF);
    EUSART1_Write(msg->from);
    EUSART1_Write(msg->to);
    EUSART1_Write(msg->msg_type);
    EUSART1_Write(MSG_EOF);

    while (!EUSART1_is_tx_done()) ;

    RX_Mode();
    DBG_PUTCH(msg->from + '0');
    DBG_PRINT("->");
    DBG_PUTCH(msg->to + '0');
    DBG_PUTCH(':');
    DBG_PUTCH(msg->msg_type + '0');
    DBG_PRINT("\r\n");
  
    // (("Msg %d => %d\r\n", msg->msg_type, msg->to));
}


/**
 * ISR called when a byte is received.
 * 
 * Checks for overrun and framing errors
 * Places the byte into recv_buffer
 * 
 * No checks are made for buffer overflows.  This simply puts
 * bytes into the buffer as fast as they arrive.
 */
void message_rx_isr(void)
{
    if(RC1STAbits.OERR)
    {
        // EUSART1 error - restart
        printf("OE\r\n");
        RC1STAbits.CREN = 0;
        RC1STAbits.CREN = 1;
    }
    
    if (RC1STAbits.FERR) {
        printf("FE\r\n");
    }
    
    recv_buffer[rx_offset_in] = RC1REG;
    ++rx_offset_in;
    rx_offset_in &= RX_OFFSET_MASK;
}

/**
 * Validate and queue incoming messages
 * Used by master and slave.
 * 
 * Called by the main loop.
 * 
 * Checks rx_offset_in and rx_offset_out to see if
 * any received bytes are ready to process.
 * 
 * The first unprocessed byte in the buffer is at recv_buffer[rx_offset_out]
 * The last unprocessed byte is at recv_buffer[rx_offset_in - 1]
 * 
 */
void queue_ib_msgs() {
    uint8_t eof_offset;
    
    if (rx_offset_in == rx_offset_out) {
        return;
    }
    
    if (((rx_offset_in - rx_offset_out) & RX_OFFSET_MASK) < 5) {
        return;
    }
    
    /* We have at least 5 characters in the receive buffer */
    eof_offset = rx_offset_out;
    while (((rx_offset_in - eof_offset) & RX_OFFSET_MASK) > 1) {
        if (recv_buffer[eof_offset] == MSG_EOF) {
            queue_ib_msg(eof_offset);
            rx_offset_out = ((eof_offset + 1) & RX_OFFSET_MASK);
        }
        eof_offset = ((eof_offset + 1) & RX_OFFSET_MASK);
    }   
}

/**
 * Validate and queue one incoming message
 * 
 * Validates the 4 bytes leading up to the EOF
 * to make sure the SOF is there, and that from
 * and to make sense.
 * 
 * If the message is valid and intended for this
 * device then the message is added to the inbound
 * message queue
 * 
 * @param rx_offset the offset of the EOF in the receive buffer
 * 
 */
static void queue_ib_msg(uint8_t rx_offset) {
    struct message *msg;
    uint8_t sof;
    uint8_t from;
    uint8_t to;
    uint8_t msg_type;
    
    sof = recv_buffer[(rx_offset - 4) & RX_OFFSET_MASK];
    if (sof != MSG_SOF) {
        DBG_PRINT("IF\r\n");
        return;
    }
    from = recv_buffer[(rx_offset - 3) & RX_OFFSET_MASK];
    to = recv_buffer[(rx_offset - 2) & RX_OFFSET_MASK];
    if (to != g_my_address) {
        DBG_PRINT("NO\r\n");
        return;
    }
    msg_type = recv_buffer[(rx_offset - 1) & RX_OFFSET_MASK];


    if (ib_pi == ((ib_ci - 1) & IDX_MASK)) {
        DBG_PRINT("IBQ Full\r\n");
    } else {
        msg = &(inbound_q[ib_pi]);
        msg->from = from;
        msg->to = to;
        msg->msg_type = msg_type;
        ib_pi = ((ib_pi + 1) & IDX_MASK);
    }

}

static void RX_Mode(void) {
    TXEN_SetLow();
    RXEN_SetLow();
}

static void TX_Mode(void) {
    TXEN_SetHigh();
    RXEN_SetHigh();
}