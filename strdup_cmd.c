#include "Dshell.h"

/**
  *strdup_cmd - Entry to the function
  *@s: a pointer to a cosntant string
  *Return: new copied string
  */

char *strdup_cmd(char *s)
{
	size_t length = strlen_cmd(s) + 1;
	char *fresh_s = malloc(length);

	if (fresh_s == NULL)
	{
		perror("malloc error");
		return(NULL)
	}

		strcpy_cmd(fresh_s, s);

		return(fresh_s);
}
