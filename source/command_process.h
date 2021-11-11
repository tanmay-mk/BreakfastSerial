
#ifndef _COMMAND_PROCESS_H_
#define _COMMAND_PROCESS_H_
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
void process_command(char *input);


#endif /* _COMMAND_PROCESS_H_ */

