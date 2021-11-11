/***********************************************************************************************************************
* File Name    : command_process.h
* Project      : PES Assignment 6
* Version      : 1.0
* Description  : Contains all the function prototypes along with variable declarations for command processor
* Author       : Vishal Raj
* Creation Date: 11.10.21
***********************************************************************************************************************/
#ifndef COMMAND_PROCESS_H_
#define COMMAND_PROCESS_H_
/*
 * process command for the provided user input
 *
 * Parameters:
 *   input	  Input string provided by user
 *
 * Returns:
 *   The number of bytes actually enqueued, which could be 0. In case
 * of an error, returns -1.
 */
void process_cmd(char *input);
void accumulator(void);

//handler prototypes
void author_handler(int, char * argv[]);
void dump_handler(int, char * argv[]);
void help_handler(int ,char * argv[]);
void info_handler(int ,char * argv[]);

#endif /* COMMAND_PROCESS_H_ */
/*[EOF]*/
