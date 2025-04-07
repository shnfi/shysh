unsigned int len(char *str)
{
	unsigned char *tmp = str;
	unsigned int l = 0;
	while (*tmp++)
		l++;
	return l;
}
