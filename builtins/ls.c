#include <stdio.h>
#include <dirent.h>

#include "ls.h"

#include "../include/check_switch.h"

void ls(const char *ABSS, unsigned char *dir)
{
	const unsigned char *valid_switches = "ltrha";
	DIR *path = opendir(dir);
	struct dirent *d = readdir(path);

	char *tmp = (char *) ABSS, c;
	while (c = *tmp++) {
		if (!check_switch(valid_switches, c)) {
			printf("[ERROR] '%c' is not a valid switch for 'ls' command!\n", c);
			return;
		}
	}

	while ((d = readdir(path)) != NULL)
		printf("- %s\n", d->d_name);
}
