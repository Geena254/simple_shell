#include "shell.h"

/**
 * execute_command - Execute a command in a child process.
 * @argv: Double pointer to an array of strings containing the
 * command and arguments.
 * @env: Double pointer to an array of strings containing
 * environment variables.
 *
 * This function creates a child process using the fork
 * system call and attempts
 * to execute the specified command with the given arguments using execve.
 * If the child process is created successfully,
 * it executes the command, and the parent
 * process waits for the child process to complete.
 */

void execute_command(char **argv, char **env)
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if (child_pid == 0)
	{
		if (execve(argv[0], argv, env) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
	}
}
