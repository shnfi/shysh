#ifndef EXECUTOR_H
#define EXECUTOR_H

#define BUFFER 2048
#define WRONG_PASS "[ERR] wrong root password!"

int exec(const char *raw_cmd, const char *prog, const char **switches, const unsigned int s, unsigned char *dir, unsigned char *un, unsigned char *pass);

#endif
