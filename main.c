#include "shell.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int _putchar(char c)
{
	return write(STDOUT_FILENO, &c, 1);
}

int main(void)
{
	char line[1024];
	char *prompt = "($) ", *argvs[2];
	pid_t cpid;
	int bytes_read;
	int write_chars;

	signal(SIGINT, SIG_IGN);

	while (1)
	{
		write_chars = write(STDOUT_FILENO, prompt, strlen(prompt));
		if (write_chars == -1)
			exit(1);

		bytes_read = read(STDIN_FILENO, line, 1024);
		if (bytes_read == -1)
			exit(2);

		if (strncmp(line, "exit", 4 * sizeof(char)) == 0 || bytes_read == 0)
			exit(0);

		cpid = fork();
		if (cpid == -1)
			exit(3);
		else if (cpid == 0)
		{
			argvs[0] = strtok(line, " \n");
			argvs[1] = NULL;
			execve(argvs[0], argvs, NULL);
			perror(argvs[0]);
			exit(4);
		}
		else
			wait(NULL);
	}
	return (0);
}

