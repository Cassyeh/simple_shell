#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "main.h"

void display_prompt(void)
{
	printf("#cisfun$ ");
}

char *read_command(void)
{
	char *buffer = NULL;
	size_t bufsize = 0;
	ssize_t characters;
	
	characters = getline(&buffer, &bufsize, stdin);
	if (characters == -1) // Handle "end of file" condition
	{
		printf("\n");
		exit(EXIT_SUCCESS);
	}
	
	if (buffer[characters - 1] == '\n')
		buffer[characters - 1] = '\0'; // Remove the newline character
	return buffer;
}

void execute_command(char *command)
{
	if (strcmp(command, "exit") == 0)
	{
		free(command);
		exit(EXIT_SUCCESS);
	}

	pid_t pid = fork();
	if (pid == -1)
	{
		perror("fork error")
		exit(EXIT_FAILURE);
	}
	
	if (pid == 0) // Child process
	{
		execve(command, NULL, environ);
		print_error(command);
		exit(EXIT_FAILURE);
	}
	else // Parent process
	{
		wait(NULL); // Wait for the child process to finish
	}
}

void print_error(char *command)
{
	fprintf(stderr, "./shell: %s: No such file or directory\n", command);
}
