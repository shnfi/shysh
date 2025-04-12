#include "strcpy.h"

char *str_cpy(unsigned char *dst, unsigned char *src)
{
	unsigned char *tmp = dst;
	while ((*dst++ = *src++) != '\0');	
	return tmp;
}
