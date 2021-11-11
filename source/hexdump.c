/************************************************************************************************
PES Assignment 6
File Name: hexdump.c
Author: Tanmay Mahendra Kothale - tanmay.kothale@colorado.edu - GitHub: tanmay-mk
*************************************************************************************************/

/*	LIBRARY FILES	*/
#include <stdio.h>

/*	OTHER FILES TO BE INCLUDED	*/
#include "hexdump.h"

void hexdump(uint32_t start_address, uint32_t length)
{

	uint8_t * start_addr =(uint8_t *) start_address;

	for(int i=0;i<length;i +=16 ){

		//printing the address
		printf("%04X_%04X ",((start_address+i)>>16), (start_address+i) & 0xFFFF);

		for(int j = 0 ; j < 16 ; j++){

			if(i+j > length){
				printf("\n\r");
				return;
			}
			//printing the bytes
			printf("%02X ", *(start_addr+i+j));
		}

		printf("\n\r");
	}

}

