#include "Dshell.h"

#define BUFFER 1024
/**
 * main - entry point
 *
 * Return: 0 always on success
 */
int main(void)
{
	char *read = NULL;
	char **args;

	if (isatty(STDIN_FILENO) == 1)
	{
		interact_mode();
	}
	else
	{
		while ((read = _getline_cmd()) != NULL)
		{
			args = tokenize(read);
			process_cmd(args);
			free(args);
		}
		free(read);
	}
	return (0);
}
