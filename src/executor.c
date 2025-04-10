#include <stdio.h>
#include <stdlib.h>

#include "../include/executor.h"
#include "../utils/proc_switches.h"
#include "../utils/lower.h"
#include "../utils/strcomp.h"

void exec(const char *prog, const char **switches, const unsigned int s)
{
	const char *ABSS = proc_switches(switches, s);

	char *opt_cmd = lower(prog);
	if (str_comp(opt_cmd, "exit"))
		exit(1);
	else  
		printf("INVALID COMMAND!\n");
}
