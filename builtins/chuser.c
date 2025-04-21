#include <stdio.h>

#include "../utils/strcpy.h"
#include "../utils/len.h"

#include "chuser.h"

void chuser(unsigned char *un)
{
	printf("Enter the new username: ");

	char tmp[MAX_UN_BUFF];
	fgets(tmp, sizeof(tmp), stdin);

	tmp[len(tmp) - 1] = '\0';
	str_cpy(un, tmp);
}
