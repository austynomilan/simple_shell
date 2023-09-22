#include "Dshell.h"

/**
 * tokenize_line - split line of arguments
 * @read: length of the arguments
 * @nread: read count
 *
 * Return: split arguments in tokens
 */

char **tokenize_line(char *read, ssize_t nread)
{
	char *token, *read_copy;
	char **tokens = malloc(sizeof(char *) * (nread / 2 + 1));
	char *delim = "\n\t\r\a ";
	int i = 0;

	if (tokens == NULL)
	{
		perror("malloc");
		exit(1);
	}

	token = strtok(read, delim);

	while (token != NULL)
	{
		tokens[i] = token;
		token = strtok(NULL, delim);
		i++;
	}
	tokens[i] = NULL;

	return (tokens);
}
