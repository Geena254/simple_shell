#include "shell.h"
#define MAXIMUM_COMMAND 100

/**
 * prompt - Display a simple shell prompt and execute user commands.
 * @env: Array of strings containing the environment variables.
 * This function creates a basic shell where the user can enter commands.
 * It displays a prompt "cisfun$" and waits for the user to input a command.
 */

void prompt(char **env)
{
	size_t n = 0;
	char *string = NULL;
	ssize_t num_char;
	int i, status;
	char *argv[] = {NULL, NULL};
	pid_t child_pid;

	while(1)
	{
		if (isatty(STDIN_FILENO))
			write(1, "cisfun$ ", 9);
		num_char = getline(&string, &n, stdin);

		if (num_char == -1)
		{
			free(string);
			exit(EXIT_FAILURE);
		}
		i = 0;
		while (string[i])
		{
			if(string[i] == '\n')
			{
				string[i] = 0;
			}
			i++;
		}
		argv[0] = string;
		child_pid = fork();
		if (child_pid == -1)
		{
			free(string);
			exit(EXIT_FAILURE);
		}
		if (child_pid == 0)
		{
			if (execve(argv[0], argv, env) == -1)
			{
				write(STDERR_FILENO, argv[0], _strlen(argv[0]));
				write(STDERR_FILENO, ": ", 2);
				write(STDERR_FILENO, "No such file or directory found\n", 34);
				free(string);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			wait(&status);
			free(string);
		}
	}
}
