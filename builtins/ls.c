#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

#include "ls.h"

#include "../utils/len.h"
#include "../utils/strcpy.h"

#include "../include/check_switch.h"

void ls(const char *ABSS, const char *name, unsigned char *dir)
{
	const unsigned char *valid_switches = "ltrha";
	static char *path;
	path = malloc(len(dir) + len(name) + 10);
	str_cpy(path, dir);

	path[len(path)] = '/';

	str_cpy(path + len(dir) + 1, name);

	DIR *path_struct = opendir(path);
	struct dirent *d = readdir(path_struct);

	char *tmp = (char *) ABSS, c;
	while (c = *tmp++) {
		if (!check_switch(valid_switches, c)) {
			printf("[ERROR] '%c' is not a valid switch for 'ls' command!\n", c);
			return;
		}
	}

	while ((d = readdir(path_struct)) != NULL) {
		if ((d->d_name[0] == '.' && check_switch(ABSS, 'a')) || (d->d_name[0] != '.')) {
			printf("- ");
			if (check_switch(ABSS, 'h'))
				printf("(%s) ", d->d_type == DT_DIR ? "DRCT" : "FILE");
			printf("%s\n", d->d_name);
		}
	}
}
