/*
void printanything(char print){
    printf("%c\n", printf);


}
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<readline/readline.h>
#include"gen_cmd.h"

/* Known command key bindings */
enum command_keys
{
	info_key = first_key,
	help_key,
	radar_key,
	dac_key,
	prompt_key,
	quitsim_key,
	exit_key
};

/* Command dictionary */
static const struct commands_t fpga0[] = 
{
	{"radar NUM SUBCOMMAND", radar_key, "Issue command \"SUBCOMMAND\" to radar module \"NUM\"", "^\\s*(radar)\\s+([0-9])+\\s+(.*)$"},
	{"dac SUBCOMMAND", dac_key, "Issue a command to D/A converter module", "^\\s*(dac)\\s+(.*)\\s*$"},
	{"info", info_key, "Issue a command to generic IO module", "^\\s*(info)\\s*$"},
	{"help", help_key, "Display help", "^\\s*(help)\\s*$"},
	{"prompt", prompt_key, "Show interactive command line prompt", "^\\s*(prompt)\\s*$"},
	{"exit", exit_key, "Exit prompt", "^\\s*(exit)\\s*$"},
	{"quitsim", quitsim_key, "Exit simulation", "^\\s*(quitsim)\\s*$"},
 	{0, null_key, 0, 0} /* Last entry signaling, do not remove */
};


/*
 *	return:
 *		-1 - Comando desconhecido
 *		 0 - Comando executado com sucesso
 *		 1 - Comando para fim de simulação
 * */
int CMD_ExecFPGA0(int pFpga, const char* cmd)
{
	int key;
	char* subcommand[4];
	int result = 0;
	int i;
	int prompt = 0;
	char* pCmd = 0;

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
			pCmd = readline("fpga0>");
			/* Check if command matches any known command */
			key = command_parse(fpga0, pCmd, subcommand, 4);
		}
		else
		{
			/* Check if command matches any known command */
			key = command_parse(fpga0, cmd, subcommand, 4);
		}

		/* Execute command */
		switch(key)
		{
			case radar_key:
				/* Execute command on radar module */
				/*
                                if (CMD_ExecRadar(FPGA0_GetRadar(pFpga, strtoul(subcommand[1], 0, 10)), subcommand[2]))
				{
					result = -1;
				}
                                */
				break;

			case dac_key:
				/* Execute command on dac module */
				/*
                                if (CMD_ExecDAC(FPGA0_GetDAC(pFpga), subcommand[1]))
				{
					result = -1;
				}
                                */
				break;

			case info_key:
				/* Dump FPGA0 info */
				//FPGA0_DumpInfo(pFpga);
				break;

			case help_key:
				/* Show help */
				show_commands(fpga0);
				break;

			case prompt_key:
				/* Enable interactive prompt */
				prompt = 1;
				break;

			case exit_key:
				/* Disable interactive prompt */
				prompt = 0;
				break;

			case quitsim_key:
				/* Force exit simulation */
				result = 1;
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

