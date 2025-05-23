#include <stdio.h>
#include <stdlib.h>

#include "../include/executor.h"
#include "../utils/proc_switches.h"
#include "../utils/lower.h"
#include "../utils/strcomp.h"
#include "../utils/join.h"
#include "../include/pass_validation.h"
#include "../utils/len.h"

#include "../builtins/echo.h"
#include "../builtins/clear.h"
#include "../builtins/ls.h"
#include "../builtins/cd.h"
#include "../builtins/pwd.h"
#include "../builtins/uptime.h"
#include "../builtins/mkdir.h"
#include "../builtins/touch.h"
#include "../builtins/rm.h"
#include "../builtins/wizardsay.h"
#include "../builtins/chpass.h"
#include "../builtins/chuser.h"

static char *return_name(const char *str)
{
	if (str == "")
		return ".";

	char *out;
	char *tmp = str, c;
	int wsi = -1, i = 0;
	while (*tmp != '\0')
		*tmp++;
	*tmp--;

	while (c = *tmp--) {
		if (c == ' ') {
			wsi = i;
			break;
		}
		i++;
	}

	out = malloc(len(str) - wsi);
	if (str[0] == '-')
		for (int j = len(str) - wsi; j < len(str); j++)
			out[len(out)] = str[j];
	else
		for (int j = 0; j < len(str); j++)
			out[len(out)] = str[j];

	if (str[0] == '-' && (wsi == -1 || out == ""))
		return ".";
	
	return out;
}

int exec(const char *raw_cmd, const char *prog, const char **switches, const unsigned int s, unsigned char *dir, unsigned char *un, unsigned char *pass)
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
		ls(ABSS, return_name(join(switches, s)), dir);
	else if (str_comp(opt_cmd, "cd"))
		cd(dir, join(switches, s));
	else if (str_comp(opt_cmd, "pwd"))
		pwd(dir);
	else if (str_comp(opt_cmd, "uptime"))
		uptime();
	else if (str_comp(opt_cmd, "mkdir"))
		mkdir_(join(switches, s), dir);
	else if (str_comp(opt_cmd, "touch"))
		touch(join(switches, s), dir);
	else if (str_comp(opt_cmd, "rm"))
		rm(ABSS, return_name(join(switches, s)), dir);
	else if (str_comp(opt_cmd, "wizardsay"))
		wizard_say(join(switches, s));
	else if (str_comp(opt_cmd, "chpass"))
		if (pass_validation(pass))
			chpass(pass);
		else
			printf("%s\n", WRONG_PASS);
	else if (str_comp(opt_cmd, "chuser")) {
		if (pass_validation(pass))
			chuser(un);
		else
			printf("\n%s\n", WRONG_PASS);
	}
	else {
		char *returning_output = malloc(BUFFER);
		FILE *output;
		char string[BUFFER];

		output = popen(raw_cmd, "r");

		if (output == NULL) {
		    printf("[ERR] error while preparing the pipe!\n");
			return 1;
		}
		else {
			while (fgets(returning_output, BUFFER - 1, output))
		        printf("%s", returning_output);
		}
	}
	
	return 1;
}
