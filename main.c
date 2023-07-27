#include "shell.h"

/**
 * main - check the code
 *
 * Return: Always 0
 */
int main(void)
{
	char *prompt = "$ ", *line = NULL;
	pid_t cpid;
	size_t length = 1024;
	ssize_t bytes_read;
	char *argvs[2];
	int val;

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
		if (argvs != NULL)
		{
			cpid = fork();
			if (cpid == -1)
				exit(-1);
			if (cpid == 0)
			{
				argvs[0] = newline_del(line);
				argvs[1] = NULL;
				val = execve(argvs[0], argvs, environ);
				if (val == -1)
					perror("./shell");
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
