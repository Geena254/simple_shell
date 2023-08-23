#include "shell.h"

void handl_exit(char *string)
{
	/* Check for exit command */
	if (_strcmp(string, "exit\n") == 0)
	{
		free(string);
                exit(EXIT_SUCCESS);
	}
}
