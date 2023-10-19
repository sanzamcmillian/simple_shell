#include "shell.h"

/**
 *check_exe - check if a command is executable
 *@pathname: command entered
 *@statbuf: memory allocation for the command
 *
 *Return: boolean of (true - 1) if executable and (false - 0) otherwise
**/


int check_exe(char *pathname, struct stat *statbuf)
{
	int stat_return = 0;

	stat_return = stat(pathname, statbuf);

	if (stat_return == 0)
	{
		return (1);
	}
	return (0);
}
