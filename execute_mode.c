#include "Dshell.h"
/**
 * execute_mode - executing the tokenized arguments
 * @args: arguments
 * @read: characters read from stdin
 *
 * Return: void
 */

void execute_mode(char **args, char *read)
{
	pid_t pid = fork();
	int status;
	char *full_path;

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (args[0][0] != '/')
		{
			full_path = handle_path(args[0]);
			if (full_path != NULL)
			{
				if (execve(full_path, args, environ) == -1)
				{
					fprintf(stderr, "%s: 1: %s: not found\n", read, args[0]);
					exit(EXIT_FAILURE);
				}
				free(full_path);
			}
		}
		execve(args[0], args, environ);
		fprintf(stderr, "%s: 1: %s: not found\n", read, args[0]);
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(pid, &status, 0);

		if (WIFEXITED(status) && WEXITSTATUS(status) == 127)
		{
			fprintf(stderr, "Command not found: %s\n", read);
		}
	}
}
