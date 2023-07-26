#include "shell.h"

/**
 * *_strcat - concatenates @src to @dest
 * @src: the source string to append to @dest
 * @dest: the destiation string to be concatenated upon
 * Return:pointer to the resulting string
 */

char *_strcat(char *dest, char *src)
{
	char *copy;

	int lengthofa = strlength(dest);
	int lengthofb = strlength(src);
	int i = 0;

	copy = (char *) malloc(lengthofa + 1);
	if (copy == NULL)
		return (NULL);
	strcopy(copy, dest);
	dest = (char *)malloc(lengthofa + lengthofb + 1);
	while (copy[i] != '\0')
	{
		dest[i] = copy[i];
		i++;
	}
	i = 0;
	while (src[i] != '\0')
	{
		dest[lengthofa] = src[i];
		lengthofa++;
		i++;
	}
	dest[lengthofa] = '\0';
	free(copy);
	return (dest);
}
