#include "Dshell.h"

#define BUFFER 1024
/**
 * main - entry point
 *
 * Return: 0 always on success
 */
int main(int argc, char **argv)
{
	char *read = NULL;
	char **args;
	int status;

	(void)argc;

	if (isatty(STDIN_FILENO) == 1)
	{
		interact_mode();
	}
	else
	{
		while ((read = _getline_cmd()) != NULL)
		{
			args = tokenize(read);
			status = process_mode(args);
			if (status == 0)
			{
				execute_mode(args, argv[0]);
				free(args);
			}
		}
		free(read);
	}
	return (0);
}
