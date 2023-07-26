#include "shell.h"
/**
 * free_multiarr - function to free memory from multi-dimensional array
 * @arr: pointer to multidimensional array
 * @rows: amount of rows
 */
void free_multiarr(char **arr, int rows)
{
	int i;

	for (i = 0; i < rows; i++)
	{
		free(arr[i]);
	}
	free(arr);
}
/**
 * write_to_buff - function to write to buff
 * @string: pointer to string to be written
 */
void write_to_buff(char *string)
{
	ssize_t writer;

	writer = write(STDOUT_FILENO, string, strlength(string));
	if (writer == -1)
	{
		exit(-1);
	}
}
/**
 * get_env - function to get PATH environment variable
 * @command: command string given
 *
 * Return: pointer to string
 */
char *get_env(char *command)
{
	char *path, *full_path;
	char **argvs;
	int i;
	struct stat buff;

	path = getenv("PATH");
	if (path == NULL)
		return (NULL);
	argvs = strtoken(path, ":");
	for (i = 0; argvs[i] != NULL; i++)
	{
		full_path = _strcat(argvs[i], "/");
		full_path = _strcat(full_path, command);
		if (stat(full_path, &buff) == 0)
		{
			return (full_path);
		}
		else
		{
			free(full_path);
			continue;
		}
	}
	return (NULL);
}
