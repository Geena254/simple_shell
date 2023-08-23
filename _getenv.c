#include "shell.h"

/**
 * _getenv - get env variables
 * @name: name of variable
 * Return: pointer to env variables
 */

char *_getenv(const char *name)
{
	int i, j;
	char *env_var;

	i = 0;
	while (environ[i] != NULL)
	{
		env_var = environ[i];
		/*  Find the position of '=' character */
		j = 0;
		while (env_var[j] != '\0' && env_var[j] != '=')
		{
			j++;
		}

		if (_strncmp(env_var, name, j) == 0 && env_var[j] == '=')
		{
			return (&env_var[j + 1]);  /* Return value after the '=' character */
		}
		i++;
	}

	return (NULL); /* Variable not found */
}
