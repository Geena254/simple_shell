#include "shell.h"
#define INITIAL_BUFF_SIZE 1024
#define BUFFER_INCREMENT 1024

/**
 * my_getline - Function that reads a line from the input stream.
 * @lineptr: A pointer to the buffer where the line will be stored.
 * @m: A pointer to the size of the buffer
 * @stream: Input stream to read from (usually stdin)
 * Return: Number of characters read on success, -1 on failure.
 */

ssize_t my_getline(char **lineptr, size_t *m, FILE *stream)
{
	static char buff[INITIAL_BUFF_SIZE];
	static size_t pos;
	char c;
	ssize_t bytesRead;
	char *error;

	if (*lineptr == NULL || *m == 0)
	{
		*lineptr = buff;
		*m = INITIAL_BUFF_SIZE;
	}
	while (1)
	{
		if (pos == 0)
		{
			bytesRead = read(fileno(stream), buff,
					INITIAL_BUFF_SIZE);
			if (bytesRead <= 0)
			{
				if (bytesRead < 0)
					perror("Read error");
				else
				{
					error = "No input provided.\n";
					write(STDERR_FILENO, error,
							strlen(error));
				}
				return (-1);
			}
		}
		c = buff[pos];
		pos++;
		if (c == '\n' || c == '\0')
		{
			buff[pos - 1] = '\0';
			pos = 0;
			break;
		}
	}
	return (pos);
}
