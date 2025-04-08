#include <stdlib.h>
#include "len.h"

char *lower(char *str)
{
	char *out = malloc(len(str));
	int j = 0;
	for (int i = 0; i < len(str); i++) {
		if ((int) str[i] >= 97)
			out[j] = str[i];
		else {
			out[j] = (char) ((int) str[i]) + 32;
		}

		j++;
	}

	return out;
}
