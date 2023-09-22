#include "shell.h"

/*
 *check_exe - check if a command is executable
 *@pathname: command entered
 *@statbuf: memory allocation for the command
 *
 *Return: boolean of (true) if executable and (false) otherwise
 */


bool check_exe(char *pathname,struct stat *statbuf)
{
    int stat_return = 0;

    stat_return = stat(pathname, statbuf);

    if (stat_return == 0)
    {
        return (true);
    }
    return (false);
}
