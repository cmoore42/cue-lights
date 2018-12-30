#ifndef MESSAGES_H
#define	MESSAGES_H

#include <xc.h> 

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */
    
#define MSG_IDLE 0
#define MSG_STANDBY 1
#define MSG_READY 2
#define MSG_GO 3
#define MSG_IDLE_ACK 4
#define MSG_STANDBY_ACK 5
#define MSG_READY_ACK 6
#define MSG_GO_ACK 7
#define MSG_POLL 8
#define MSG_PRESENCE 9
    

#define MSG_SOF 0x55
#define MSG_EOF 0xaa
#define MSG_MASTER 0
    
#define QSIZE 64
#define IDX_MASK 0x3f

struct message {
    uint8_t from;
    uint8_t to;
    uint8_t msg_type;
};

extern uint8_t ob_pi;
extern volatile uint8_t ob_ci;
extern volatile uint8_t ib_pi;
extern uint8_t ib_ci;
extern struct message outbound_q[QSIZE];
extern struct message inbound_q[QSIZE];

/*
 * A queue is empty if PI == CI
 * A queue is full if PI == (CI-1)
 * 
 * To add:
 *  - write to queue[PI}
 *  - increment PI
 * To remove:
 *  - read from queue[CI]
 *  - increment CI
 * 
 * For the outbound queue the main program is the producer and 
 * the ISR is the consumer.  Main updates PI, ISR updates CI.
 * 
 * For the inbound queue the main program is the consumer and
 * the ISR is the producer.  Main updates CI, ISR updates PI.
 */

extern void message_send(uint8_t from, uint8_t to, uint8_t msg);
extern struct message *message_recv(void);
extern void message_init(void);
extern uint8_t message_avail(void);
extern void message_ob_process(void);
extern void queue_ib_msgs(void);

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif

