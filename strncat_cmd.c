#include "Dshell.h"

/**
  *strncat_cmd - Entry point to the code
  *@flat: place where the source string is appended
  *@source: the source
  *@number: number untill source
  *Return: pointer to flat
  */
char *strncat_cmd(char *flat, char *source, int number)
{
	int x;
	int length = strlen_cmd(flat);

	for (x = 0; source[x] != source[number]; x++, length++)
	{
		flat[length] = source[x];

		return (flat);
}
