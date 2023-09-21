#include "Dshell.h"

/**
 * tokenize - split line of arguments
 * @read: length of the arguments
 *
 * Return: split arguments in tokens
 */

char **tokenize(char *read)
{
	char *token, *read_copy;
	char **tokens = malloc(sizeof(char *) * MAX_LEN);
	char *delim = "\t\r\n\a ";
	int i = 0;

	if (tokens == NULL)
	{
		perror("malloc");
		exit(1);
	}

	read_copy = strdup(read);

	token = strtok(read, delim);

	while (token != NULL)
	{
		tokens[i] = strdup(token);
		token = strtok(NULL, delim);
		i++;
	}
	tokens[i] = NULL;
	free(read_copy);

	return (tokens);
}
