#include <stdio.h>
#include "len.h"
#include "arr_len.h"

unsigned int arr_len(const char **arr, unsigned int s)
{
	unsigned int arr_len = 0;
	for (int i = 0; i < s; i++)
		for (int j = 0; j < len(arr[i]); j++)
			arr_len++;

	return arr_len;
}
