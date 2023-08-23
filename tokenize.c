#include "shell.h"

/**
 * tokenize_input -  Function that checs string
 * @input: string to check
 * @argv: arguements value
 */

void tokenize_input(char *input, char **argv)
{
	int k;

	k = 0;
	argv[k] = strtok(input, " ");
	while (argv[k] != NULL)
	{
		k++;
		argv[k] = strtok(NULL, " ");
	}
}
