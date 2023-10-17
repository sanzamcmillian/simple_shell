#include "shell.h"

/**
 *split_line - splits a string into multiple strings
 *@line: the string received to be broke into multiple strings
 *
 *Return: the split string
**/

#define TOKEN_DELIMITERS " \t\r\n\a"

char **split_line(char *line)
{
	int bufsize = 64, position = 0;
	char **tokens = malloc(bufsize * sizeof(char*));
 	char *token;

    	token = strtok(line, TOKEN_DELIMITERS);
    	while (token != NULL)
	{
        	tokens[position] = token;
        	position++;

        if (position >= bufsize)
	{
            	bufsize += 64;
            	tokens = realloc(tokens, bufsize * sizeof(char*));
        }

        token = strtok(NULL, TOKEN_DELIMITERS);
    	}
    	tokens[position] = NULL;
    	return tokens;
}
