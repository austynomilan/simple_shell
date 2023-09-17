#include "Dshell.h"

/**
 * check_delim - check for delimiter in the character
 * @c: character
 * @delim: delimiter
 *
 * Return: 0 if not a delimiter and 1 if it is
 */
bool check_delim(const char *delim, char c)
{
	unsigned int i;

	for (i = 0; delim[i] != '\0'; i++)
	{
		if (c == delim[i])
			return (true);
	}
	return (false);
}

/**
 * _strtok_cmd - split a string into tokens
 * @str: string
 * @delim: delimiter
 * Return: NULL or pointer to the following token
 */

char *strtok_cmd(char *str, const char *delim)
{
	static char *token = NULL;
	char *tokenS = NULL;

	if (str != NULL)
	{
		token = str;
	}

	if (token == NULL || *token == '\0')
	{
		return (NULL);
	}

	while (*token != '\0' && check_delim(delim, *token))
	{
			token++;
	}

	if (*token == '\0')
	{
		token = NULL;
		return (NULL);
	}

	tokenS = token;

	while (*token != '\0' && !check_delim(delim, *token))
	{
			token++;
	}

	if (*token != '\0')
	{
		*token++ = '\0';
	}

	return (tokenS);

}
