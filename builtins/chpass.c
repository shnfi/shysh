#include <stdio.h>

#include "chpass.h"

#include "../utils/strcomp.h"
#include "../utils/strcpy.h"

void chpass(unsigned char *old_p)
{
	char tmp[MAX_PASS_BUFF];

	printf("Enter the new password: ");
	fgets(tmp, sizeof(tmp), stdin);
	str_cpy(old_p, tmp);

	printf("\n[MSG] Password has been changed!\n");
}
