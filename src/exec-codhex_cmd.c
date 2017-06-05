#include<stdio.h>
#include<stdlib.h>
#include<readline/readline.h>
#include"gen_cmd.h"
#include"split-bitstream_wrapper.h"

/* Known command key bindings */
enum command_keys
{
    info_key = first_key,
    help_key,
    code_key,
    decode_key,
    prompt_key,
    exit_key
};

/* Command dictionary */
static const struct commands_t exec_codhex[] = 
{
    {"info", info_key, "Issue a command to codhex module", "^\\s*(info)\\s*$"},
    {"help", help_key, "Display help", "^\\s*(help)\\s*$"},
    {"code   DATA TYPE", code_key, "Issue command \"TYPE\" to code \"DATA\"", "^\\s*(code)\\s+(0[x][0-9a-fA-F]+)+\\s+(.*)$"},
    {"decode DATA TYPE", decode_key, "Issue command \"TYPE\" to decode \"DATA\"", "^\\s*(decode)\\s+([0-9])+\\s+(.*)$"},
    {"prompt", prompt_key, "Show interactive command line prompt", "^\\s*(prompt)\\s*$"},
    {"exit", exit_key, "Exit prompt", "^\\s*(exit)\\s*$"},
    {0, null_key, 0, 0} /* Last entry signaling, do not remove */
};

int CMD_RcCodhex(const char* cmd){

    int result = 0;
    int key = 0;
    int i = 0;
    int prompt = 0;
    char* subcommand[4];
    char* pCmd = 0;

    CSplitBitstream *p = NULL;

    p = SplitBitstream_new('A');
    
    Chex2bin(p);

    do
    {
    
    	/* Initialize pointers */
    	for(i = 0; i < 4; i++)
    	{
    	    subcommand[i] = 0;
    	}
    
    	if (prompt)
    	{
    	    /* Show prompt and get a command line */
    	    pCmd = readline("rc-codhex>");
    	    /* Check if command matches any known command */
    	    key = command_parse(exec_codhex, pCmd, subcommand, 4);
    	}
    	else
    	{
    	    /* Check if command matches any known command */
    	    key = command_parse(exec_codhex, cmd, subcommand, 4);
    	}
    
    	/* Execute command */
    	switch(key)
    	{
    	    case info_key:
    	        /* Dump RcCodhex info */
                printf("info_key\n");
    	    break;
    
    	    case help_key:
    	        /* Show help */
    	        show_commands(exec_codhex);
    	    break;
    
    	    case code_key:
    	        /* Execute command on coding module */
                printf("code\n");
                printf("subcommand: %s\n", subcommand[1]);
                result = 0;
    	    break;
    
    	    case decode_key:
    	        /* Execute command on decoding module */
                printf("decode\n");
                printf("subcommand: %s\n", subcommand[1]);
                result = 0;
    	    break;
    
    	    case prompt_key:
    	        /* Enable interactive prompt */
    	        prompt = 1;
                result = 0;
    	    break;
    
    	    case exit_key:
                printf("\n");
    	        /* Disable interactive prompt */
    	        prompt = 0;
    	    break;
    
    	    default:
    	        /* Unknown command */
    	        if (prompt)
    	        {
    	            printf("Unknown command \"%s\", type \"help\" for help.\n", pCmd ? pCmd : "");
    		}
    	        else
    		{
    		    printf("Unknown command \"%s\", type \"help\" for help.\n", cmd ? cmd : "");
    		}
    		result = -1;
    	    break;
    	}
    
    	/* Free subcommands strings */
    	for(i = 0; i < 4; i++)
    	{
    	    if (subcommand[i])
    	    {
    		free(subcommand[i]);
    	    }
    	}
    
    	if (pCmd)
    	{
    	    free(pCmd);
    	}
    }while(prompt);
    
    /* Return 0 if command was successfully executed, any other value otherwise */
    return result;
}

