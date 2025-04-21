#include <stdio.h>

#include "../utils/strcomp.h"

#include "../include/pass_validation.h"

int pass_validation(unsigned char *pass)
{
	printf("Enter the root password: ");

	char tmp[MAX_PASS_BUFFER];
	fgets(tmp, sizeof(tmp), stdin);

	if (str_comp(tmp, pass))
		return 1;
	else 
		return 0;
}
