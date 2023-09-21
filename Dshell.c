#include "Dshell.h"

#define BUFFER 1024
/**
 * main - entry point
 * @argc: argument count
 * @argv: arguments passed
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
		char *line = NULL;
		size_t len = 0;

		while ((getline(&line, &len, stdin)) != -1)
		{
			args = tokenize(line);
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
