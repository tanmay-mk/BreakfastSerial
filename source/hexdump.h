/************************************************************************************************
PES Assignment 6
File Name: hexdump.h
Author: Tanmay Mahendra Kothale - tanmay.kothale@colorado.edu - GitHub: tanmay-mk
*************************************************************************************************/
#ifndef _HEXDUMP_H_
#define _HEXDUMP_H_

/*	LIBRARY FILES	*/
#include <stdint.h>

/*	FUNCTION PROTOTYPE	*/

/*
 * @brief: 		prints the hexdump of length bytes
 *
 * @parameters:
 * 		start_address 	: the adderss from which the hex dump is
 * 							to be printed
 *
 * 		length			: length of bytes of the hexdump to be printed
 *
 *
 * @returns: none
 */
void hexdump(uint32_t start_address, uint32_t length);


#endif /* _HEXDUMP_H_ */

