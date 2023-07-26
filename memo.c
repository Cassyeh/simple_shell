#include "shell.h"

/**
* _puts - prints the string
* @str: string
*/

void _puts(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);
	_putchar('\n');
}

/**
* _memset - char function
* @s: prm
* @n: prm
* @b: prm
* Return: prm
*/

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int a;

	for (a = 0; a < n; a++)
	{
		s[a] = b;
	}
	return (s);
}

path.c#include "shell.h"

/**
* _splitPATH - int function
* @str: prm
* Return: num Path
*/

int _splitPATH(char *str)
{
	int a;
	int count = 0;
	int srcflg = 1;

	for (a = 0; str[a]; a++)
	{
		if (str[a] != ':' && srcflg == 1)
		{
			count += 1;
			srcflg = 0;
		}
		if (str[a + 1] == ':')
		{
			srcflg = 1;
		}
	}
	return (count);
}

/**
* _PATHstrcmp - int function
* @s1: prm
* @s2: prm
* Return: zero
*/

int _PATHstrcmp(const char *s1, const char *s2)
{
	int a;

	for (a = 0; s2[a] != '='; a++)
	{
		if (s1[a] != s2[a])
			return (-1);
	}
	return (0);
}

/**
* _con_cat - charcter function
* @arg: vrbl
* @tok: vrbl
* @tmp: vrbl
* Return: zero
*/

char *_con_cat(char *tmp, char **arg, char *tok)
{
	int len = 0;

	_memset(tmp, 0, 256);
	len = _strlen(tok) + _strlen(arg[0]) + 2;
	_strcat(tmp, tok);
	_strcat(tmp, "/");
	_strcat(tmp, arg[0]);
	tmp[len - 1] = '\0';
	return (tmp);
}

realloc.c#include "shell.h"

/**
* _memcpy - copy infos between void ptrs
* @newptr: destination ptr
* @ptr: the source pointer
* @size: the size of the new ptr
* Return: 0
*/

void _memcpy(void *newptr, const void *ptr, unsigned int size)
{
	char *char_newptr = (char *)newptr;
	char *char_ptr = (char *)ptr;
	unsigned int i;

	for (i = 0; i < size; i++)
		char_newptr[i] = char_ptr[i];
}

/**
* _realloc - reallocates a memory block
* @ptr: pointer to the memory prev allocated
* @old_size: size in bytes of the allocated space of pointer
* @new_size: new size in bytes of the new memory block
* Return: pointer
*/

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *newptr;

	if (ptr == NULL)
		return (malloc(new_size));

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (new_size == old_size)
		return (ptr);

	newptr = malloc(new_size);
	if (newptr == NULL)
		return (NULL);

	if (new_size < old_size)
		_memcpy(newptr, ptr, new_size);
	else
		_memcpy(newptr, ptr, old_size);

	free(ptr);
	return (newptr);
}
