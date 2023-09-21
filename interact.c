#include "Dshell.h"

/**
 * interact_mode - Entry point itno the shell
 *
 * Return: always 0 (success)
  */

void interact_mode(void)
{
	char *read = NULL;
	size_t len = 0;
	ssize_t nread;
	int process = 1;
	char **args;

	while (process == 1)
	{
		printf("(Dshell) $: ");
		nread = getline(&read, &len, stdin);
		
		if (nread == -1)
		{
			perror("getline");
			break;
		}

		args = tokenize_line(read, nread);
		process_cmd(args);
		free(args);
	}
	free(read);
}
