#include <stdio.h>
#include "line_accumulate.h"
#include "command_process.h"
#include <stdint.h>

void accumulate_line(void)
{
	uint8_t c=0;
	uint8_t buffer[80];
	uint8_t bp = 0;

	//receive
	while((c != '\r' ) && (c != '\n')){
		c = getchar();
		if(c == '\b'){
			bp--;
			printf("\b \b");
		}else{
			sprintf((char *) buffer+bp,(char *) &c);//try putchar
			bp++;
			printf("%c",(char)c);
		}
	}
	printf("\r\n");
	bp = 0;
	process_command((char *)buffer);
	printf("? ");
	c = 0;
}
