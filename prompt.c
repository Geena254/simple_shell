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
	char *argv[] = {NULL, NULL};
	int status;
	pid_t child_pid;
	ssize_t num_char;

	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);
		if ((num_char = getline(&string, &n, stdin)) == -1)
		{
			free(string);
			break;
		}
		/* removing newline character */
		remove_newline(string);

		argv[0] = string;
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Fork");
			exit(EXIT_FAILURE);
		}
		if (child_pid == 0)
		{
			if (execve(argv[0], argv, env) == -1)
			{
				write(STDERR_FILENO, argv[0], _strlen(argv[0]));
				write(STDERR_FILENO, ": ", 2);
				write(STDERR_FILENO, "No such file or directory found\n", 34);
				exit(1);
			}
		}
		else
			wait(&status);
		free(string);
		free(argv);
	}
}
