#include "shell.h"

/**
* _strcpy - copies the content of the source string to destination string
* @dest: destination argument
* @src: source arg
* Return: copy of string
*/
char *_strcpy(char *dest, const char *src)
{
	char *tmp = dest;

	while (*src != '\0')
	{
		*dest++ = *src++;
	}
	*dest = '\0';

	return (tmp);
}

/**
* _strncpy - copies the content of the source to destination
* @dst: argument
* @src: argument
* @n: argument
* Return: copy of string
*/
char *_strncpy(char *dst, const char *src, size_t n)
{
	char *dst_c = dst;

	while (n > 0 && *src != '\0')
	{
		*dst++ = *src++;
		n--;
	}
	while (n > 0)
	{
		*dst++ = '\0';
		n--;
	}
	return (dst_c);
}
