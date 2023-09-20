#include "Dshell.h"

/**
  *strcmp_cmd - Entry point
  *@stringa: pointer to the first string
  *@stringb: pointer to the second sting
  *Return: differnece
  */

int strcmp_cmd(char *stringa, char *stringb)
{
	while (*stringa == *stringb && (*stringa != '\0' && *stringb != '\0'))
	{
		stringa++;
		stringb++;
	}
	return (*stringa - *stringb);
}
