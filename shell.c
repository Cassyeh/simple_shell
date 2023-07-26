#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include "shell.h"

int execute_command(char *command) {
    pid_t pid;
    int status;

    pid = fork();
    if (pid == 0) {
        char *args[] = {command, NULL}; // Arguments array
        execve(command, args, NULL);
        perror("execve"); // This line is reached only if execve fails
        _exit(EXIT_FAILURE);
    } else if (pid > 0) {
        wait(&status); // Wait for the child process to finish
    } else {
        perror("fork");
        return -1;
    }

    return status;
}
