#include "Dshell.h"

/**
  *strcpy_cmd - Entry to the program
  *@flat: where the source string is to be copied
  *@source: the source of string
  *Return: a cpoied string
  */

char *strcpy_cmd(char *flat, char *source)
{
	int len = 0;
	int x;

	while (source[len] != '\0')
		len++;
		for (x = 0; x <= len; x++)
			flat[x] = source[x]

			return (flat);
			}
