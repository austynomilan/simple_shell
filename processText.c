#include "Dshell.h"

/**
  * inputDefiner - Entry to the progra
  * @read_len: length of the text
  * @text_cpy: copy of text
  *
  * Return: always 0 (success)
  */

char **inputDefiner(char *text_cpy, ssize_t read_len)
{
	char *delim = " \n";
	char *token;
	char **args;
	int i;

	args = malloc(sizeof(char *) * read_len);
	i = 0;

	token = strtok(text_cpy, delim);

	while (token != NULL)
	{
		args[i] = token;
		token = strtok(NULL, delim);
		i++;
	}

	args[i] = NULL;

	return (args);
	}

