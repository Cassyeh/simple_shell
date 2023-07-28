#include "shell.h"

/**
* get_env - char function
* Return: NULL
*/

char *get_env(const char *nam)
{
	int a, result;

	for (a = 0; environ[a]; a++)
	{
		result = _PATHstrcmp(nam, environ[a]);
		if (result == 0)
		{
			return (environ[a]);
		}
	}
	return (NULL);
}

/**
* _env - print the environ
* Return: zero
*/

int _env(void)
{
	int a;

	for (a = 0; environ[a]; a++)
		_puts(environ[a]);
	return (0);
}

/**
* _print_str - writes a string into the standard output
* @str: string
* Return: number of characters printed
*/

int _print_str(char *str)
{
	int i = 0;

	if (str == NULL)
	{
		write(1, "(null", 6);
		return (6);
	}
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
	return (i);
}

/**
* _print_num - function prints an number integer
* @n: integer
*/
void _print_num(int n)
{
	unsigned int n1;

	if (n < 0)
	{
		n1 = -n;
		_putchar('-');
	}
	else
	{
		n1 = n;
	}
	if (n1 / 10)
	{
		_print_num(n1 / 10);
	}
	_putchar((n1 % 10) + '0');
}
