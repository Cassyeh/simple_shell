#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "shell.h"

int execute_command(char *command) {
	pid_t pid;
	int status;
	
	pid = fork();

	if (pid == -1) {
		perror("fork error");
		return 1;
	}

	if (pid == 0) {
		execve(command, NULL, NULL);
		perror(command);
		_exit(EXIT_FAILURE);
    } else {
	    wait(&status);
	    return status;
    }
}
