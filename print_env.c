#include <unistd.h>
#include <string.h>

/**
 * print_environment - Function that prints environment variables
 * @env: An array of environment variables
 */

void print_environment(char **env)
{
	int i;

	i = 0;
	while (env[i] != NULL)
	{
		size_t len = strlen(env[i]);

		write(STDOUT_FILENO, env[i], len);
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}
