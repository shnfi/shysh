#include <stdio.h>

#include "chpass.h"

#include "../utils/strcomp.h"
#include "../utils/strcpy.h"

void chpass(unsigned char *old_p)
{
	printf("Enter the old password: ");
	
	char tmp[MAX_PASS_BUFFER];
	fgets(tmp, sizeof(tmp), stdin);

	if (str_comp(tmp, old_p)) {
		printf("Enter a new password: ");
		fgets(tmp, sizeof(tmp), stdin);
		str_cpy(old_p, tmp);

		printf("\nPassword has been changed!\n");
	}
	else
		printf("Oh, don't you know the current password?!\n");
}
