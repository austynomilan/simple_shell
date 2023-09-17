#include "Dshell.h"

/**
*atoi_cmd - converts string to an integer
* @str: string input
*
* Return: integer number
*/

int atoi_cmd(char *str)
{
	char c;
	unsigned int i, n = 0, j = strlen_cmd(str) - 1, null = -1;
	int flag = 0, sign = 1;

	for (i = 0; i <= j; i++)
	{
		c = str[i];
		if (c == '-')
			sign *= -1;
		if (c >= 48 && c <= 57)
		{
			n = n * 10 + (c - '0');
			flag = 1;
		}
		if (flag == 1)
		{
			if (!(c >= 48 && c <= 57))
				break;
		}
	}
	if (sign == -1)
	{
		n *= -1;
	}
	if (j == null)
		return (0);
	return (n);
}
