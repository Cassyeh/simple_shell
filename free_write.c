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
