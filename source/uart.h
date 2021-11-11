/***********************************************************************************************************************
* File Name    : uart.h
* Project      : PES Assignment 6
* Version      : 1.0
* Description  : Contains all the function prototypes along with variable declarations for uart module
* Author       : Vishal Raj & referred from Dean chp 8-https://github.com/alexander-g-dean/ESF/tree/master/NXP/Code/
* 				 Chapter_8/Serial-Demo.
* Creation Date: 11.10.21
***********************************************************************************************************************/
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

//extern cbfifo_t *rx_fifo;
//extern cbfifo_t *tx_fifo;


#endif /* UART_H_ */
