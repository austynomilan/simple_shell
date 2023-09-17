#include "Dshell.h"

/**
 * handle_path - handling the PATH
 * @cmd: command to be handled
 *
 * Return: full path om success & NULL if
 * there is error
 */
char *handle_path(char *cmd)
{
	char *path = getenv("PATH");
	char *dir = strtok(path, ":");
	char *full_path = malloc(strlen_cmd(dir) + strlen_cmd(cmd) + 2);
	char *cmd_cpy;

	if (access(cmd, X_OK) == 0)
	{
		cmd_cpy = strdup(cmd);
		return (cmd_cpy);
	}

	while (dir != NULL)
	{
		strcpy_cmd(full_path, dir);
		strcat_cmd(full_path, "/");
		strcat_cmd(full_path, cmd);

		if (access(full_path, X_OK) == 0)
		{
			return (full_path);
		}

		dir = strtok(NULL, ":");
	}

	free(full_path);
	return (NULL);
}
