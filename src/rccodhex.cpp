#include"../include/rccodhex_cmd.h"
#include"../include/rccodhex.hpp"
#include<iostream>

using namespace std;


int main (int argc, char **argv){

    struct arguments arguments;
    int result = 0;

    /* default options */
    memset(&arguments, 0, sizeof(arguments));

    /* parse command line */
    argp_parse(&argp, argc, argv, 0, 0, &arguments);

    /* display selected options when verbose is enabled */
    display_options(&arguments);

    /* exec command */
    if (exec_command(&arguments))
    {
        cout << "Failure to exec command line" << endl;
    	/* failure */
    	result |= -1;
    }

    if (exec_batch(&arguments))
    {
        cout << "Failure to exec batch file" << endl;
    	/* failure */
    	result |= -1;
    }

    return result;
}
