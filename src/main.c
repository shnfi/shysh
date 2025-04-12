/*
 * MIT License
 * Copyright (C) 2025 shnfi
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy...
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#include "../utils/len.h"

#include "../include/token_sep.h"
#include "../include/executor.h"

#define DEFAULT_UN "shyshUser"
#define SETUP_PROMPT(un, priv) un, priv
#define MAX_CMD_BUFF 300

static char *PRIV(unsigned int c)
{
	if (c == 1) 
		return  "user";
	else if (c == 2)
		return "super user";
}


static void strip_nl(unsigned char *str)
{
	for (int i = 0; i < len(str); i++) {
		if (str[i] == '\n') {
			str[i] = '\0';
			break;
		}
	}
}

typedef struct user_stct {
	unsigned int priv;
	unsigned char *un;
	unsigned char *cmd;
	unsigned char *dir;
} uinfo;

int main(void)
{
	uinfo ustng = { 1, DEFAULT_UN, malloc(MAX_CMD_BUFF), getcwd(NULL, 1024) };

	while (1) {
		printf("%s%s ", SETUP_PROMPT(ustng.un, PRIV(ustng.priv) == "super user" ? "#" : "$"));
		fgets(ustng.cmd, 100, stdin);

		strip_nl(ustng.cmd);

	 	unsigned int size = 0;
		char **tokens = token_sep(ustng.cmd, &size);

		char *prog = tokens[0];
		char **switches = malloc(20 * sizeof(char *));
		for (int i = 1; i < size; i++) {
			switches[i - 1] = malloc(20);
			switches[i - 1] = tokens[i];
		}
		
		if (!exec(prog, (const char **) switches, size - 1, ustng.dir))
			break;
	}

	free(ustng.cmd);

	return 0;
}
