#include "shell.h"

/**
 * main - check the code
 * @val: Return value for execve
 * @argvs: An array of pointers to the arguments.
 *
 * Return: Always 0
 */
int main(int val, char **argvs)
{
	char *prompt = "$ ", *line = NULL;
	pid_t cpid;
	size_t length = 1024;
	ssize_t bytes_read;

	write_to_buff(prompt);
	bytes_read = getline(&line, &length, stdin);
	while (bytes_read != -1)
	{
		if (strspace(line) == 1)
		{
			write_to_buff(prompt);
			bytes_read = getline(&line, &length, stdin);
			continue;
		}
		argvs = strtoken(line);
		if (argvs != NULL)
		{
			cpid = fork();
			if (cpid == -1)
				return (-1);
			if (cpid == 0)
			{
				val = execve(argvs[0], argvs, NULL);
				if (val == -1)
					perror("Error");
				exit(0);
			}
			else
				wait(NULL);
		}
		write_to_buff(prompt);
		bytes_read = getline(&line, &length, stdin);
	}
	free(line);
	write_to_buff("\n");
	return (0);
}
