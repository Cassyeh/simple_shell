#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>
#include <stdlib.h>

/**
 * test - function to test fork
 *
 * Return: 0 on success
 */
int test(void)
{
	char **argv = (char **)malloc(2 * sizeof(char *));

	argv[0] = "/bin/ls";
	argv[1] = NULL;

	if (fork() == 0)
	{
		int val = execve(argv[0], argv, NULL);

		if (val == -1)
		{
			perror("Error\n");
		}
	}
	else
	{
		wait(NULL);
		printf("CT: child has terminated\n");
	}
	printf("Bye\n");
	return (0);
}
