/************************************************************************************************
PES Assignment 6
File Name: main.c
Author: Tanmay Mahendra Kothale - tanmay.kothale@colorado.edu - GitHub: tanmay-mk
		Howdy Pierce - howdy.pierce@colorado.edu
*************************************************************************************************/

#include <stdint.h>
#include <stdio.h>
#include <MKL25Z4.h>

#include "test_cbfifo.h"
#include "command_process.h"
#include "line_accumulate.h"
#include "sysclock.h"
#include "uart.h"
#include "cbfifo.h"

/*
 * @brief: 	application entry point
 */
int main(void)
{
  //initialize clock
  sysclock_init();
  //initialize UART0 with baud rate = 38400
  Init_UART0(38400);
  //test the cbfifo implementations
  test_cbfifo();

  printf("Welcome to BreakfastSerial!\r\n");
  printf("? ");
  while (1)
  {
	accumulate_line();
  }

  return 0 ;
}

