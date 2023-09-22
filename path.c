#include "shell.h"

/**
 *resolve_path - handles path opf command to environment
 *@cmd:  command to be checked
 *
 *Return: the new pathname if exits in the files, else Null
**/


char *resolve_path(char *cmd) {
	char *original_PATH = getenv("PATH");
	if (!original_PATH)
	{
		return (NULL);
	}
	char local_PATH[strlen(original_PATH) + 1];
	strcpy(local_PATH, original_PATH);

	char *p = strtok(local_PATH, ":");
	char *resolved_path = malloc(PATH_MAX);  // PATH_MAX from limits.h

	while (p != NULL) {
		snprintf(resolved_path, PATH_MAX, "%s/%s", p, cmd);

        	struct stat sb;
        	if (stat(resolved_path, &sb) == 0 && sb.st_mode & S_IXUSR) {
            		return resolved_path;
        	}

        	p = strtok(NULL, ":");
    	}

    	free(resolved_path);
    	return NULL;
}
