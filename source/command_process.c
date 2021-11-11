
#include "command_process.h"
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include "hexdump.h"

typedef void (*cmd_handler_t)(int, char * argv[]);

static void author_handler(int, char * argv[]);
static void dump_handler(int, char * argv[]);
static void help_handler(int ,char * argv[]);
static void info_handler(int ,char * argv[]);

typedef struct{
	const char *cmd_name;
	cmd_handler_t handler;
	const char * help_string;
}cmd_table_t;

static const cmd_table_t commands[] = {
		{"author",author_handler,"Prints the name of the Author\r\n"},
		{"dump",dump_handler,"Print a dump of memory represented as hex values. Write dump <start address> <length of dump>\n\r"},
		{"help",help_handler,"Print this help message\r\n"},
		{"info",info_handler,"Prints the build info\r\n"}
};

static const int cmd_nos = sizeof(commands) / sizeof(cmd_table_t);

void process_command(char *input)
{
	bool in_token = false;
	char *argv[10];
	int argc = 0;

	bool command = false;

	char *p = input;
	char *end;

	for(end=input ; *end!= '\0' ; end++)
		;
	memset(argv,0,sizeof(argv));

	for(p = input; p < end; p++){

		switch(in_token){

		case false:
			if(
					((*p>='a')&&(*p<='z')) ||
					((*p>='A')&&(*p<='Z')) ||
					((*p>='0')&&(*p<='9'))
			  )
			{
				argv[argc] = p;
				argc++;
				in_token = true;
			}

		break;
		case true:
			if(
					(*p == ' ')  ||
					(*p == '\t') ||
					(*p == '\n') ||
					(*p == '\r')
			  )
			{
				*p = '\0';
				in_token = false;
			}

		break;
		}
	}
	if(argc == 0){//no command found
		return;
	}

	//Todo:Handle the command
	for (int i=0; i < cmd_nos; i++) {
	    if (strcasecmp(argv[0], commands[i].cmd_name) == 0) {
	      commands[i].handler(argc, argv);
	      command = true;
	      break;
	    }

	  }
	 if(!command) {printf("Invalid command: %s\r\n",argv[0]);}
}

void author_handler(int a, char * argv[])
{
	printf("Tanmay Mahendra Kothale\n\rtanmay.kothale@colorado.edu\n\rGitHub: tanmay-mk\r\n");
}

void dump_handler(int a, char * argv[])
{
	uint32_t len = 0;
	uint32_t start = 0;

	sscanf(argv[1],"%x",&start);

	if(strstr((char*)argv[2],"0x") || strstr((char*)argv[2],"0X"))//if input is in hex
		{sscanf(argv[2],"%x",&len);}
	else
		{sscanf(argv[2],"%d",&len);}

	if(len>640){
		printf("Length out of range.Enter length between 1 to 640 or 0x01 to 0x280\r\n");
		return;
	}

	hexdump(start,len);
}

void help_handler(int argc,char * argv[])
{
	printf("author\r\n");
	printf("%s",commands[0].help_string);
	printf("dump\r\n");
	printf("%s",commands[1].help_string);
	printf("help\r\n");
	printf("%s",commands[2].help_string);
	printf("info\r\n");
	printf("%s",commands[3].help_string);
}

void info_handler(int argc,char * argv[])
{

}

