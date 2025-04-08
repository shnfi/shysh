#include <stdlib.h>

#include "proc_switches.h"
#include "len.h"

char *proc_switches(const char **switches, const unsigned int s)
{
	char *out = malloc(20);
	int k = 0;
	for (int i = 0; i < s; i++) {
		for (int j = 0; j < len((char *) switches[i]); j++) {
			if (switches[i][j] != ' ' && switches[i][j] != '-') {
				out[k] = switches[i][j];
				k++;
			}
		}
	}

	return out;
}
