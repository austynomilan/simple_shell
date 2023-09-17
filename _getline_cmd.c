#include "Dshell.h"

/**
 * _getline_cmd - read user input from stdin
 * Return: buffer of character read from user
 */

char *_getline_cmd()
{
	char *buffer = malloc(sizeof(char) * BUFF_SIZE);
	ssize_t bytes_read;
	char line = 0;
	int i = 0;

	if (buffer == NULL)
		return (NULL);

	while (1)
	{
		bytes_read = read(STDIN_FILENO, &line, 1);
		if (bytes_read == -1)
		{
			perror("read");
			free(buffer);
			return (NULL);
		}
		else if (bytes_read == 0)
		{
			free(buffer);
			return (NULL);
		}
		if (line == '\n')
		{
			break;
		}
		if (i + 1 >= BUFF_SIZE)
		{
			buffer = realloc(buffer, i + 1);
			if (buffer == NULL)
			{
				perror("realloc");
				free(buffer);
				return (NULL);
			}
		}
		buffer[i++] = line;
	}
	buffer[i] = '\0';
	return (buffer);
}
