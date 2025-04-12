#include <stdio.h>
#include <dirent.h>

#include "ls.h"

void ls(const char *ABSS, unsigned char *dir)
{
	DIR *path = opendir(dir);
	struct dirent *d = readdir(path);

	while ((d = readdir(path)) != NULL) {
		printf("- %s\n", d->d_name);
	}
}
