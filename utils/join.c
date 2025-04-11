#include <stdlib.h>
#include "join.h"

#include "len.h"

char *join(const char **arr, const unsigned int s)
{
	char *out = malloc(1000); // change the value later, i hope you don't forget
	unsigned int k = 0;

	for (int i = 0; i < s; i++) {
		for (int j = 0; j < len(arr[i]); j++) {
			out[k] = arr[i][j];
			k++;
		}
		out[k] = ' ';
		k++;
	}

	return out;
}
