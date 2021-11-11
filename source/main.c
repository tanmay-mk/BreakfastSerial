
#include "sysclock.h"
#include "uart.h"
#include "stdint.h"
#include <stdio.h>
#include "cbfifo.h"
#include "MKL25Z4.h"
#include "test_cbfifo.h"
#include "command_process.h"
#include "line_accumulate.h"

int main(void)
{
  sysclock_init();
  Init_UART0(38400);
  test_cbfifo();

  printf("Welcome to BreakfastSerial!\r\n");
  printf("? ");
  while (1)
  {
	accumulate_line();
  }

  return 0 ;
}

