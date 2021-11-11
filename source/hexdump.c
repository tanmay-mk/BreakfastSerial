
#include "hexdump.h"
#include <stdio.h>


void hexdump(uint32_t start, uint32_t len)
{

	uint8_t * start_addr =(uint8_t *) start;

	for(int i=0;i<len;i +=16 ){

		printf("%04X",((start+i)>>16));
		printf("_");
		printf("%04X	",((start+i) & 0xFFFF));

		for(int j = 0 ; j < 16 ; j++){

			if(i+j > len){
				printf("\n\r");
				return;
			}
			printf("%02X ", *(start_addr+i+j));
		}

		printf("\n\r");
	}

}

/*[EOF]*/
