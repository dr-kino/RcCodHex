#include<stdlib.h>
#include<string.h>
#include"../include/rccodhex_cmd.h"
#include"../include/exec-codhex_cmd.h"
#include"split-bitstream_wrapper.h"

/*******************************************************************************
***  Global Variables  *********************************************************
*******************************************************************************/
const char *argp_program_version =
"rc-codhex 0.1";
const char *argp_program_bug_address =
"<rafaelll.cavalcanti@gmail.com>";
     
/* Parse command line options */
error_t parse_opt(int key, char *arg, struct argp_state *state)
{
	/* Get the input argument from argp_parse, which we
	know is a pointer to our arguments structure. */
	struct arguments *arguments = state->input;
	     
	switch (key)
	{
	    case key_verbose: 
	       	arguments->verbose++;
                printf("verbose\n");
		break;

	    case key_code:
	       	arguments->code = 1;
	        arguments->code_arg = arg;
                printf("code\n");
		break;

	    case key_decode:
	        arguments->decode = 1;
	        arguments->decode_arg = arg;
                printf("decode\n");
		break;
	
	    case key_execute:
	        arguments->cmd = 1;
	       	arguments->cmd_arg = arg;
                printf("execute\n");
		break;

	    case key_batch:
	        arguments->batch = 1;
	        arguments->batch_arg = arg;
                printf("batch\n");
		break;

	case ARGP_KEY_ARG:
		//if (state->arg_num >= 2)
		///* Too many arguments. */
		//argp_usage (state);
		//
		//arguments->args[state->arg_num] = arg;
		
		break;
	     
	case ARGP_KEY_END:
		//if (state->arg_num < 2)
		///* Not enough arguments. */
		//argp_usage (state);
		break;
	     
	default:
		/* Unknown argument */
		return ARGP_ERR_UNKNOWN;
	}

	/* Success */
	return 0;
}

/* display selected options when verbose is enabled */
void display_options(struct arguments* arguments)
{
	if (arguments->verbose)
	{
	       printf("verbose level: %i\n", arguments->verbose);
	       printf("Signal coding: %s\n", arguments->code ? "yes" : "no"); 
	       printf("Bandbase coding type: \"%s\"\n", arguments->code_arg ? arguments->code_arg : ""); 
	       printf("Signal decode: %s\n", arguments->decode ? "yes" : "no");
	       printf("Bandbase decoding type: \"%s\"\n", arguments->decode_arg ? arguments->decode_arg : "");
	       printf("Execute command: %s\n", arguments->cmd ? "yes" : "no");
	       printf("Command: \"%s\"\n", arguments->cmd_arg ? arguments->cmd_arg : "");
	}
}

/* exec prompt option */
int exec_command(struct arguments* arguments)
{
    int result = 0;
    int cmdresult = 0;

    CSplitBitstream *p = NULL;

    p = SplitBitstream_new('A');
    
    Chex2bin(p);

	/* Execute command if any available */
	if (arguments->cmd)
	{
		cmdresult =  CMD_RcCodhex(arguments->cmd_arg);
		/* Execute command */
		if (cmdresult == -1)
		{
			result |= -1;
		}
		else if(cmdresult == 1)
		{		
			// Executa comando específco //
		}
		else
		{
			/* MISRA-C */
		}
	}

	/* return result */
	return result;
}

/* exec batch file */
int exec_batch(struct arguments* arguments)
{
	int result = 0;
	FILE* pFile = 0;
	char* str = 0;
	size_t strlen = 0;
	unsigned int i;
	int exec;

	/* Execute command if any available */
	if (arguments->batch && arguments->batch_arg)
	{
		/* Open file */
		pFile = fopen(arguments->batch_arg, "r");
		if (!pFile)
		{
			/* failed opening file */
			result |= -1;
			printf("Unable to open file \"%s\"\n", arguments->batch_arg);
		}
		else
		{
			/* read each line and execute */
			getline(&str, &strlen, pFile);
			i = 0;
			exec = 0;
			while(!feof(pFile) && !exec)
			{
				/* Execute command */
				//exec = Executa comando específico //
				if (exec)
				{
					/* Command failed */
					result |= -1;
					printf("Failed to execute command at line %u on file %s.\n", i + 1, arguments->batch_arg);
				}
				/* Read next line */
				getline(&str, &strlen, pFile);
				i++;
			}
		}
	}

	/* Close file if opened */
	if(pFile)
	{
		fclose(pFile);
	}

	/* Free string if any allocated */
	if(str)
	{
		free(str);
	}

	/* return result */
	return result;
}

