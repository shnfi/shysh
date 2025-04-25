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

	while ((d = readdir(path)) != NULL) {
		if ((d->d_name[0] == '.' && check_switch(ABSS, 'a')) || (d->d_name[0] != '.')) {
			printf("- ");
			if (check_switch(ABSS, 'h'))
				printf("(%s) ", d->d_type == DT_DIR ? "DRCT" : "FILE");
			printf("%s\n", d->d_name);
		}
	}
}
