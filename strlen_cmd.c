#include "Dshell.h"

/**
  *strlen_cmd - Entry to the function
  *@string: pointer to a string
  *Return: the initial counter
  */

int strlen_cmd(char *string)
{
	int start = 0;

	while (string[start] != '\0')
		start++;

	return (start);
}
