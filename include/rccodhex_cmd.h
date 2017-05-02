#ifndef RCCODHEX_CMD
#define RCCODHEX_CMD

#ifdef __cplusplus
extern "C"{
#endif

#include<stdlib.h>
#include<string.h>
#include<argp.h>
#include<argz.h>
#include<stdio.h>
#include"gen_cmd.h"

/* Program documentation. */
static char doc[] =
"Command line application to emulate bandbase coding.";

enum key_options
{
	key_verbose     = 'v',
	key_batch       = 'b',
	key_code        = 'c',
	key_decode      = 'd',
	key_execute     = 'e',
	/* Force to stay away from ordinary printable ascii codes */
	last_key        = 128
};

/* Used by main to communicate with parse_opt. */
struct arguments
{
	/* Set verbose level */
	int verbose;
	/* Coding type*/
	int code;
	/* Selected bandbase coding */
	char* code_arg;
	/* Decoding type */
	int decode;
	/* Selected bandbase decoding */
	char* decode_arg;
	/* Enable command execution */
	int cmd;
	/* Command to be executed */
	char* cmd_arg;
	/* Enable execution of batch file */
	int batch;
	/* Batch file to be executed */
	char* batch_arg;
};

/* The options we understand. */
static struct argp_option options[] = 
{
	{"verbose",     key_verbose ,   0,              0, "Produce verbose output",                        0},
	{"code",        key_code,       "CODE_TYPE",    0, "Coding protocol with CODE_TYPE argument",       0},
	{"decode",      key_decode,     "DECODE_TYPE",  0, "Decoding protocol with DECODE_TYPE argument",   0},
	{"execute",     key_execute,    "COMMAND",      0, "Execute COMMAND on this card",                  0},
	{"batch",       key_batch,      "BATCH",        0, "Execute batch file BATCH",                      0},
	{ 0, 0, 0, 0, 0, 0}
};

/* This prototype is here since it is required by argp */
error_t parse_opt(int, char*, struct argp_state*);

/* argp parser. */
static struct argp argp = { options, parse_opt, 0, doc, 0, 0, 0 };

/* display selected options when verbose is enabled */
void display_options(struct arguments* arguments);

/* exec prompt option */
int exec_command(struct arguments* arguments);

/* exec batch file */
int exec_batch(struct arguments* arguments);

#ifdef __cplusplus
} // extern "C"
#endif

#endif // RCCODHEX_CMD
