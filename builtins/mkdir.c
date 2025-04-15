#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

#include "mkdir.h"

#include "../utils/len.h"
#include "../utils/strcpy.h"

void mkdir_(const char *name, unsigned char *dir)
{
	char *path = malloc(len(dir) + len(name) + 10);
	str_cpy(path, dir);

	path[len(path)] = '/';

	int j = 0;
	for (int i = len(dir); i < len(dir) + len(name); i++) {
		path[i + 1] = name[j];
		j++;
	}

	mkdir(path, 0755);

	free(path);
}
