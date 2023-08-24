#include "shell.h"
#include <stdio.h>

/**
 * main - main arguments functions
 * @ac:count of argumnents
 * @env: environment
 * Return: _exit = 0.
 */

int main(int ac, char ** env)
{
	if (ac == 1)
	{
         prompt(env);
	}

	return (0);
}
