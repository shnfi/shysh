#ifndef EXECUTOR_H
#define EXECUTOR_H

#define BUFFER 2048

int exec(const char *raw_cmd, const char *prog, const char **switches, const unsigned int s, unsigned char *dir);

#endif
