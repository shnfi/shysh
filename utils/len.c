unsigned int len(const char *str)
{
	unsigned char *tmp = (char *) str;
	unsigned int l = 0;
	while (*tmp++)
		l++;
	return l;
}
