
#include "hexdump.h"
#include <stdio.h>


void hexdump(uint32_t start_address, uint32_t length)
{

	uint8_t * start_addr =(uint8_t *) start_address;

	for(int i=0;i<length;i +=16 ){

		printf("%04X_%04X ",((start_address+i)>>16), (start_address+i) & 0xFFFF);

		for(int j = 0 ; j < 16 ; j++){

			if(i+j > length){
				printf("\n\r");
				return;
			}
			printf("%02X ", *(start_addr+i+j));
		}

		printf("\n\r");
	}

}

/*[EOF]*/
