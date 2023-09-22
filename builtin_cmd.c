#include "Dshell.h"
/**
  *get_cmd_func - Entry to the function
  *@s: a pointer to the string
  *Return: Always 0 (success)
  */

int (*get_cmd_func(char *s))(char **)
{
	builtinCmd built[] = {
		{"exit", exit_cmd},
		{"env", env_cmd},
		{"cd", cd_cmd},
		{NULL, NULL}
	};
	int i = 0;

	if (s == NULL || strlen_cmd(s) == 0)
		return (NULL);

	while (built[i].cmd != NULL && strcmp_cmd(built[i].cmd, s) != 0)
		i++;

	return (built[i].f);
}

/**
 * exit_cmd - exits the shell
 * @args: parameter argument
 * Return: 0 to exit
 */

int exit_cmd(char **args)
{
	int status;

	if (args[1] != NULL)
	{
		status = atoi_cmd(args[1]);
		exit(status);
	}
	else
	{
		exit(0);
	}
}

/**
 * env_cmd - prints the current environment
 * @args: parameter argument
 *
 * Return: always 0
 */
int env_cmd(char **args)
{
	int i;

	(void)**args;

	for (i = 0; environ[i] != NULL; i++)
	{
		printf("%s\n", environ[i]);
	}
	return (1);
}


/**
 * cd_cmd - command use for changing directory
 * @args: arguments comprises of command and directory
 *
 * Return: 0 to indicate successful execution
 */
int cd_cmd(char **args)
{
	char *prevDir;
	const char *path;
	char currentDir[PATH_MAX_LENGTH];
	int rVal;

	if (args[1] == NULL)
	{
		rVal = chdir(getenv("HOME"));
	}
	else if (args[1] != NULL)
	{
		path = args[1];
		rVal = chdir(path);

		if (strcmp_cmd(args[1], "-") == 0)
		{
			prevDir = getenv("OLDPWD");
			rVal = chdir(prevDir);
		}
	}
	else
	{
		perror("cd error");
		return (1);
	}

	if (rVal != -1)
	{
		getcwd(currentDir, sizeof(currentDir));
		setenv("OLDPWD", getenv("PWD"), 1);
		setenv("PWD", currentDir, 1);
	}
	else if (rVal == -1)
	{
		perror("hsh");
		return (1);
	}

	return (0);

}
