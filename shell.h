#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <stdbool.h>

char **split_line(char *line);
int check_exe(char *pathname, struct stat *statbuf);
char *resolve_path(char *cmd);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);

#endif
