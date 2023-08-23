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
	int k, length, status;
	char *argv[MAXIMUM_COMMAND];
	pid_t child_pid;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(1, "cisfun$ ", 9);
		num_char = getline(&string, &n, stdin);
		if (num_char == -1)
		{
			free(string);
			exit(EXIT_FAILURE);
		}
		/* removing the newline character */
		length = _strlen(string);
		if (length > 0 && string[length - 1] == '\n')
		{
			string[length - 1] = '\0';
		}

		/* Check for exit command */
		if (_strcmp(string, "exit\n") == 0)
		{
			free(string);
			exit(EXIT_SUCCESS);
		}
		/* Add a check for the 'env' command */
		else if (_strcmp(string, "env\n") == 0)
		{
			print_environment(env);
		}
		k = 0;
		argv[k] = strtok(string, " ");
		while (argv[k] != NULL)
		{
			k++;
			argv[k] = strtok(NULL, " ");
		}
		i/*  Handle PATH using the new function */
			handle_path(argv); /*  Call the new function to handle PATH */

		/*  If executable not found, skip fork and print error message */
		if (argv[0] == NULL || access(argv[0], X_OK) != 0)
		{
			printf("%s: command not found\n", argv[0]);
			continue;
		}

		/* Call the extracted function to execute the command */
		execute_command(argv, env);
	}
}
