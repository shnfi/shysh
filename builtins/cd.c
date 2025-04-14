#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "cd.h"

#include "../utils/len.h"
#include "../utils/strcpy.h"

void cd(unsigned char *dir, const unsigned char *p)
{
	unsigned char *np = malloc(len(dir) + len(p) + 10);
	str_cpy(np, dir);
	unsigned int j = 0;
	printf("%d\n", len(dir) + len(p));

	np[len(np)] = '/';

	for (int i = len(dir); i < len(dir) + len(p); i++) {
		np[i + 1] = p[j];
		j++;
	}

	chdir(np);
	getcwd(dir, 1024);

	free(np);
}
