#include <stdio.h>

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

int exec(const char *prog, const char **switches, const unsigned int s, unsigned char *dir)
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
	else  
		printf("INVALID COMMAND!\n");
	
	return 1;
}
