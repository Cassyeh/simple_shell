#include "shell.h"

/**
 * strlength - function to calculate length of string
 * @string: given string
 *
 * Return: length of string
 */
int strlength(char *string)
{
	int length = 0;

	if (string == NULL)
	{
		return (0);
	}
	while (string[length] != '\0')
	{
		length++;
	}
	return (length);
}

/**
 * strcompare - function to compare two strings
 * @str_1: first string
 * @str_2: second string
 *
 * Return: true(1) or false(0)
 */
int strcompare(char *str_1, char *str_2)
{
	int i;
	int length_1 = strlength(str_1);
	int length_2 = strlength(str_2);

	if (length_1 == 0 || length_2 == 0)
		return (0);
	if (length_1 != length_2)
		return (0);
	for (i = 0; i < length_1; i++)
	{
		if (str_1[i] == str_2[i])
			continue;
		else
			return (0);
	}
	return (1);
}

/**
 * strcopy - function to copy strings
 * @new_str: destination string
 * @old_str: string to be copied from
 */
void strcopy(char *new_str, char *old_str)
{
	char temp_str;
	int i = 0;
	int length = strlength(old_str);

	if (length != 0)
	{
		while (old_str[i] != '\0' && i < length)
		{
			temp_str = old_str[i];
			new_str[i] = temp_str;
			i++;
		}
		new_str[length] = '\0';
	}
}
/**
 * strspace - function to check for whitespaces
 * @string: string to be checked
 *
 * Return: 1 if all whitespaces, 0 if chareacter other than whitespace
 */
int strspace(char *string)
{
	int i = 0;
	int length = strlength(string);

	if (length == 0)
		return (1);

	while (string[i] != '\0')
	{
		if ((string[i] >= 9 && string[i] <= 13) || string[i] == ' ')
		{
			i++;
			continue;
		}
		else
			return (0);
	}
	return (1);
}
/**
 * strtoken - function to split strings into array of words
 * @line: string to be split
 *
 * Return: pointer to array of strings
 */
char **strtoken(char *line)
{
	char **argvs;
	char *copy;
	char *token;
	int i, num_tokens = 0;

	copy = (char *) malloc(strlength(line) + 1);
	if (copy == NULL)
	{
		return (NULL);
	}
	strcopy(copy, line);
	token = strtok(copy, " \t\n");
	while (token != NULL)
	{
		token = strtok(NULL, " \t\n");
		num_tokens++;
	}
	num_tokens++;
	free(copy);
	copy = (char *) malloc(strlength(line) + 1);
	if (copy == NULL)
	{
		return (NULL);
	}
	strcopy(copy, line);
	token = strtok(copy, " \t\n");
	argvs = (char **) malloc(num_tokens * sizeof(char *));
	for (i = 0; token != NULL; i++)
	{
		argvs[i] = (char *) malloc(strlength(token) + 1);
		strcopy(argvs[i], token);
		token = strtok(NULL, " \t\n");
	}
	argvs[i] = NULL;
	free(copy);
	return (argvs);
}
