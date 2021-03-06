/************************************************************************************************
PES Assignment 6
File Name: line_accumulate.c
Author: Tanmay Mahendra Kothale - tanmay.kothale@colorado.edu - GitHub: tanmay-mk
		Alexander G. Dean
*************************************************************************************************/

/*	LIBRARY FILES	*/
#include <stdio.h>
#include <stdint.h>

/*	OTHER FILES TO BE INCLUDED	*/
#include "line_accumulate.h"
#include "command_process.h"


void accumulate_line(void)
{
	uint8_t c=0;
	uint8_t buffer[80];
	uint8_t bp = 0;

	while((c != '\r' ) && (c != '\n'))
	{
		c = getchar();
		if(c == '\b')		//check for backspace
		{
			bp--;			//if backspace is present, overwrite
			printf("\b \b");
		}
		else
		{
			buffer[bp] = c;
			bp++;
			printf("%c",(char)c);
		}
	}
	buffer[bp] = '\0';
	printf("\r\n");
	bp = 0;
	process_command((char *)buffer);
	printf("\n\r? ");
	c = 0;
}
