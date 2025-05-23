#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

#include "mkdir.h"

#include "../utils/len.h"
#include "../utils/strcpy.h"

void mkdir_(const char *name, unsigned char *dir)
{
	static char *path;
	path = malloc(len(dir) + len(name) + 1);
	str_cpy(path, dir);

	path[len(path)] = '/';

	str_cpy(path + len(dir) + 1, name);

	path[len(path)] = '\0';

	mkdir(path, 0755);

	free(path);
}
