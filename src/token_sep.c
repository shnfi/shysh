#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

#include "../utils/len.h"

char **token_sep(unsigned char *cmd, unsigned int *s)
{
	char **tokens = malloc(20 * sizeof(char *));
	int j = 0, k = 0;

	for (int i = 0; i < 20; i++)
		tokens[i] = malloc(10);

	for (int i = 0; i < len(cmd); i++) {
		if (cmd[i] != ' ') {
            tokens[j][k] = cmd[i];
            k++;
        }

        else if (cmd[i] == ' ') {
            j++;
            k = 0;
			*s += 1;
        }
    }

	*s += 1;

	return tokens;
}
