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

#define TOKEN_DELIMETERS " \t\r\n\a"
char **split_line(char *line);

bool check_exe(char *pathname, struct stat *statbuf);
char *resolve_path(char *cmd);

#endif
