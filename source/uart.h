
#ifndef UART_H_
#define UART_H_
#include <stdint.h>
#include "cbfifo.h"

#define UART_OVERSAMPLE_RATE 	(16)
#define SYS_CLOCK				(24e6)
#define UART_INTERRUPTS			1

void Init_UART0(uint32_t baud_rate);
uint8_t UART0_Receive_Poll(void);
void UART0_Transmit_Poll(uint8_t data);
void Send_String(uint8_t *str);

#endif /* UART_H_ */
