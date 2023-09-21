#include "Dshell.h"

/**
 * interact_mode - Entry point itno the shell
 *
 * Return: always 0 (success)
  */

void interact_mode(void)
{
	char *read = NULL;
	int process = 1;
	char **args;


	while (process == 1)
	{
		write(1, "(Dshell) $: ", 12);
		read = _getline_cmd();

		if (read == NULL)
			continue;

		args = tokenize(read);
		process_cmd(args);
		
		free(read);
		free(args);
	}
}
