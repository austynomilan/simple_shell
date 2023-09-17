#include "Dshell.h"

/**
 * execute_cmd - execute commands
 * @args: arguments
 *
 * Return: 0 always success
 */

int execute_cmd(char **args)
{
	pid_t pid = fork();
	int status;

	if (pid == 0)
	{
		if (args[0][0] != '/')
		{
			char *full_path = handle_path(args[0]);

			if (full_path != NULL)
			{
				if (execve(full_path, args, environ) != -1)
				{
					perror("execve");
					exit(EXIT_FAILURE);
				}
			}
			else
			{
				fprintf(stderr, "%s: %d: %s: not found\n", args[0], getpid(), args[0]);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			if (execve(args[0], args, environ) == -1)
				perror("execve");
		}
	}
	else if (pid < 0)
	{
		perror("fork");
	}
	else
	{
		waitpid(pid, &status, 0);
	}
	return (1);
}

