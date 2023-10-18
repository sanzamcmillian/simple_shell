#include "shell.h"

/**
 *main - core of the program
 *@argc: counts the number of commands
 *@argv: stores the commannds in string format
 *@env: the environment with all the executable commands
 *
 *Return: on success returns (0), otherwise push errors
**/


int main(int argc, char *argv[], char **env)
{
	char *buff = NULL, *prompt = "$ ";
	size_t buff_size = argc;
	ssize_t bytes;
	pid_t wpid;
	int w_status;
	int from_pipe = 0;
	struct stat statbuf;
 	char *resolved_path = NULL;
 	char *command_to_run;

    	while(!from_pipe)
    	{
        	if (isatty(STDIN_FILENO) == 0)
			from_pipe = 1;

        	write(STDOUT_FILENO, prompt, 2);

        	/*receive command */
        	bytes = _getline(&buff, &buff_size, stdin);
        	if (bytes == -1)
        	{
            		perror("Error (getline)");
            		free(buff);
            		exit(EXIT_FAILURE);
        	}

        	if (buff[bytes - 1] == '\n')
            	buff[bytes - 1] = '\0';
        	argv = split_line(buff);

		if (!argv[0])
		{
			free(argv);
			continue;
		}
        	if (strcmp(argv[0], "exit") == 0)
		{
            		free(buff);
			buff = NULL;
           	 	free(argv);
            		exit(0);
        	}
        	if (strcmp(argv[0], "env") == 0 || strcmp(argv[0], "printenv") == 0)
		{
            		char **current_env_var = env;
            		while (*current_env_var)
 			{
                		printf("%s\n", *current_env_var);
                		current_env_var++;
                	}
            	free(buff);
		buff = NULL;
            	free(argv);
            	continue; /* Move to next iteration of the loop to await next command */
		}

        	resolved_path = resolve_path(argv[0]);
        	command_to_run = resolved_path ? resolved_path : argv[0];

        	if (!check_exe(command_to_run, &statbuf))
        	{
            		perror("Error (file status)");
            		free(resolved_path);
            		free(argv);
            		continue;
        	}

        	wpid = fork();

        	if (wpid == -1)
        	{
            		perror("Error (fork)");
            		free(buff);
			buff = NULL;
            		free(argv);
            		free(resolved_path);
            		exit(EXIT_FAILURE);
        	}
        	if (wpid == 0)
        	{
            		execve(command_to_run, argv, env);
            		perror("Error (execve)");
            		exit(EXIT_FAILURE);
        	}


        	if (waitpid(wpid, &w_status, 0) == -1)
        	{
            		perror("Error (wait)");
            		free(argv);
            		free(buff);
			buff = NULL;
            		exit(EXIT_FAILURE);
        	}
        	free(argv);
        	free(command_to_run);
	}
    	free(buff);
	buff = NULL;
    	return (0);
}
