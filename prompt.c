#include "shell.h"

#define MAXIMUM_COMMAND 10

/**
 * prompt - Display a simple shell prompt and execute user commands.
 * @env: Array of strings containing the environment variables.
 * This function creates a basic shell where the user can enter commands.
 * It displays a prompt "cisfun$" and waits for the user to input a command.
 */
void prompt(char **av, char **env)
{
	size_t n = 0;
	char *string = NULL;
	char *argv[] = {NULL, NULL};

	int  status;
	pid_t child_pid;
	ssize_t num_char;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(1, "cisfun$ ", 9);
		num_char =  getline(&string, &n, stdin);
		if (num_char == -1)
		{
			free(string);
			exit(EXIT_FAILURE);
		}

		remove_newline(string);

		argv[0] = string;
		child_pid = fork();
		if (child_pid == -1)
		{
			free(string);
			exit(EXIT_FAILURE);
		}
		if(child_pid == 0)
		{ 
			if(execve(argv[0], argv, env) == -1)
			{
				printf("%s: no such file or directory found\n", av[0]);
				free(string);
				exit(EXIT_FAILURE);
			}
		}
		else
		{ 
			wait(&status);
		}


	}
}
