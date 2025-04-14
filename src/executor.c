#include <stdio.h>
#include <stdlib.h>

#include "../include/executor.h"
#include "../utils/proc_switches.h"
#include "../utils/lower.h"
#include "../utils/strcomp.h"
#include "../utils/join.h"

#include "../builtins/echo.h"
#include "../builtins/clear.h"
#include "../builtins/ls.h"
#include "../builtins/cd.h"
#include "../builtins/cd.h"
#include "../builtins/pwd.h"

int exec(const char *raw_cmd, const char *prog, const char **switches, const unsigned int s, unsigned char *dir)
{
	const char *ABSS = proc_switches(switches, s);

	char *opt_cmd = lower(prog);
	
	/*
	 * exit command
	 */

	if (str_comp(opt_cmd, "exit"))
		return 0;

	/*
	 * other commands
	 */

	if (str_comp(opt_cmd, "echo"))
		echo(join(switches, s));
	else if (str_comp(opt_cmd, "clear"))
		clear();
	else if (str_comp(opt_cmd, "ls"))
		ls(ABSS, dir);
	else if (str_comp(opt_cmd, "cd"))
		cd(dir, join(switches, s));
	else if (str_comp(opt_cmd, "pwd"))
		pwd(dir);
	else {
		char *returning_output = malloc(BUFFER);
		FILE *output;
		char string[BUFFER];

		output = popen(raw_cmd, "r");

		if (output == NULL) {
		    printf("ERROR WHILE PREPARING THE PIPE\n");
			return 1;
		}
		else {
			while(fgets(returning_output, BUFFER-1, output))
		        printf("%s", returning_output);
		}
	}
	
	return 1;
}
