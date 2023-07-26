#include "shell.h"

/**
* _strncmp - fonction cmopares at most n characters of
*            the strings s1 and s2
*@s1: 1st string
*@s2: 2sec string
*@n: name of each environment
* Return: zero
*/

int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		else if (s1[i] == '\0')
		{
			return (0);
		}
	}
	return (0);
}
