#include <stdio.h>
#include "../include/check_switch.h"

unsigned int check_switch(const char *ABSS, const char switch_)
{
	char *tmp = (char *) ABSS, c;
	while (c = *tmp++)
		if (c == switch_)	
			return 1;
	return 0;
}
