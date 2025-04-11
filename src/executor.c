#include <stdio.h>

#include "../include/executor.h"
#include "../utils/proc_switches.h"
#include "../utils/lower.h"
#include "../utils/strcomp.h"
#include "../utils/join.h"

#include "../builtins/exit.h"
#include "../builtins/echo.h"

void exec(const char *prog, const char **switches, const unsigned int s)
{
	const char *ABSS = proc_switches(switches, s);

	char *opt_cmd = lower(prog);
	if (str_comp(opt_cmd, "exit"))
		quit();
	if (str_comp(opt_cmd, "echo"))
		echo(join(switches, s));
	else  
		printf("INVALID COMMAND!\n");
}
