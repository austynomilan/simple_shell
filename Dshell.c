#include "Dshell.h"

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
	size_t len = 0;
	ssize_t nread;

	(void)argc;

	if (isatty(STDIN_FILENO) == 1)
	{
		interact_mode();
	}
	else
	{
		while ((nread = getline(&read, &len, stdin)) != -1)
		{
			args = tokenize_line(read, nread);
			status = process_mode(args);

			if (status == 0)
			{
				execute_mode(args, argv[0]);
			}
			free(args);
		}

		free(read);
	}

	return (0);
}

