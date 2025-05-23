#include <stdio.h>
#include <stdlib.h>

#include "rm.h"

#include "../include/check_switch.h"

#include "../utils/len.h"
#include "../utils/strcpy.h"

void rm(const char *ABSS, const char *name, unsigned char *dir)
{
	const unsigned char *valid_switches = "rf";
	static char *path;
	path = malloc(len(dir) + len(name) + 1);
	str_cpy(path, dir);

	char *tmp = (char *) ABSS, c;
	while (c = *tmp++) {
		if (!check_switch(valid_switches, c)) {
			printf("[ERROR] '%c' is not a valid switch for 'ls' command!\n", c);
			return;
		}
	}

	path[len(path)] = '/';

	str_cpy(path + len(dir) + 1, name);

	path[len(path)] = '\0';

	remove(path);

	free(path);
}
