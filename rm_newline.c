#include "shell.h"

/**
 * remove_newline - Function that removes a new line
 * @input: string to check.
 * Return: Nothing.
 */

void remove_newline(char *input)
{
	int length;

	length = _strlen(input);
	if (length > 0 && input[length - 1] == '\n')
	{
		input[length - 1] = '\0';
	}
}
