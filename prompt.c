#include "shell.h"

#define MAXIMUM_COMMAND 10

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
	char *argv[MAXIMUM_COMMAND];

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

		handl_exit(string);
		remove_newline(string);
		/* Add a check for the 'env' command */
		if (_strcmp(string, "env\n") == 0)
		{
			print_environment(env);
		}

		tokenize_input(string, argv);
		/*  Handle PATH by calling  the new function */
		handle_path(argv);
		/*  If executable not found, skip fork and print error message */
		if (argv[0] == NULL || access(argv[0], X_OK) != 0)
		{
			write(STDOUT_FILENO, argv[0], _strlen(argv[0]));
			write(STDOUT_FILENO, ": command not found\n", 20);
			continue;
		}
		/* Call the extracted function to execute the command */
		execute_command(argv, env);
	}
}
