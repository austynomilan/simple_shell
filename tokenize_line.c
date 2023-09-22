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
	char *token;
	char **tokens = malloc(sizeof(char *) * nread);
	char *delim = " \t\r\n\a";
	int i = 0;

	if (tokens == NULL)
	{
		free(tokens);
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
