#include "shell.h"

#define MAXIMUM_COMMAND 10

/**
 * prompt - Display a simple shell prompt and execute user commands.
 * @av: Array of strings containing the program name and arguments.
 * @env: Array of strings containing the environment variables.
 * This function creates a basic shell where the user can enter commands.
 * It displays a prompt "cisfun$" and waits for the user to input a command.
 */
void prompt(char **av, char **env)
{
	size_t n = 0;
	char *string = NULL;
	ssize_t num_char;
	int k, i, status;
	char *argv[MAXIMUM_COMMAND];
	pid_t child_pid;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(1, "cisfun$ ", 9);
		num_char = my_getline(&string, &n, stdin);
		if (num_char == -1)
		{
			free(string);
			exit(EXIT_FAILURE);
		}
		i = 0;
		while (string[i])
		{
			if (string[i] == '\n')
				string[i] = '\0';
			i++;
		}
		handl_exit(string);

		/* Add a check for the 'env' command */
		if (_strcmp(string, "env\n") == 0)
			print_environment(env);

		k = 0;
		argv[k] = strtok(string, " ");
		while (argv[k] != NULL)
		{
			k++;
			argv[k] = strtok(NULL, " ");
		}
		/*  Handle PATH by calling the new function */
		handle_path(argv);
		/*  If executable not found, skip fork and print error message */
		if (argv[0] == NULL || access(argv[0], X_OK) != 0)
		{
			printf("%s: command not found\n", argv[0]);
			continue;
		}

		child_pid = fork();
		if (child_pid == -1)
		{
			free(string);
			exit(EXIT_FAILURE);
		}

		if (child_pid == 0)
		{
			if (execve(argv[0], argv, env) == -1)
				printf("%s: no such file or directory found\n", av[0]);
			free(string);
			exit(EXIT_FAILURE);
		}
		else
			wait(&status);
	}
}
