#include "shell.h"

/**
 * handl_exit - Function that terminates program
 * when user types 'exit'
 * @string: The string to check
 * Return: Nothing.
 */

void handl_exit(char *string)
{
	/* Check for exit command */
	if (_strcmp(string, "exit\n") == 0)
	{
		exit(EXIT_SUCCESS);
	}
}
