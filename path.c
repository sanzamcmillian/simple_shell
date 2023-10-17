#include "shell.h"
#define MAX_PATH_SIZE 2040

/**
 *resolve_path - handles path opf command to environment
 *@cmd:  command to be checked
 *
 *Return: the new pathname if exits in the files, else Null
**/


char *resolve_path(char *cmd)
{
	char *original_PATH = getenv("PATH");
	struct stat sb;
	char *local_path = NULL;
	char *p = NULL;
	char *resolved_path = NULL;

	if (!original_PATH)
		return (NULL);


	local_path = (char *) malloc(strlen(original_PATH) + 1);
	strcpy(local_path, original_PATH);

	p = strtok(local_path, ":");
	resolved_path = malloc(PATH_MAX);  /* PATH_MAX from limits.h */

	while (p != NULL)
	{
		snprintf(resolved_path, PATH_MAX, "%s/%s", p, cmd);
        	if (stat(resolved_path, &sb) == 0 && sb.st_mode & S_IXUSR)
		{
            		return resolved_path;
        	}
        	p = strtok(NULL, ":");
    	}
	free(local_path);
    	free(resolved_path);
    	return NULL;
}
