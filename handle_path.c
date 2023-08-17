#include "shell.h"

/**
 * handle_path - get PATH
 * @argv: name of command
 *
 */

void handle_path(char **argv)
{
	/*   Get the value of the PATH environment variable */
	char *path = _getenv("PATH");
	/* Tokenize the PATH variable using ':' as the delimiter */
	char *token = strtok(path, ":");
	/*   Store the maximum length for the command path */
	size_t max_length = 100;
	char *command_path = (char *)malloc(max_length);

	if (command_path == NULL)
	{
		exit(EXIT_FAILURE);
	}

	/*    Iterate through each directory in the PATH */
	while(token != NULL)
	{
		/*  Construct the full path to the command executable */
		_strncpy(command_path, token, max_length - 1);
		command_path[max_length - 1] = '\0';
		_strcat(command_path, "/");
		_strcat(command_path, argv[0]);

		/*  Check if the constructed path is an executable file and accessible */
		if(access(command_path, X_OK) == 0)
		{
			argv[0] = strcpy(argv[0], command_path);
			break; /* Stop searching further */
		}

		/* Move on to the next directory in PATH */
		token = strtok(NULL, ":");
	}
	free(command_path);
}
