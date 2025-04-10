#include <stdio.h>
#include "strcomp.h"

int str_comp(char *str1, char *str2)
{
	unsigned char t1, t2;
	while (1) {
		t1 = *str1++;
		t2 = *str2++;
		if (t1 != t2)
			return 0;
		if (!t1)
			break;
	}

	return 1;
}
