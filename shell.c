#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "shell.h"

int execute_command(char *command) {
    pid_t pid;

    pid = fork();
    if (pid == -1) {
        perror("fork error");
        return -1;
    }
    if (pid == 0) {
        char *args[2]; /* Arguments array */
        args[0] = command;
        args[1] = NULL;
        if (execve(command, args, NULL) == -1) {
            perror("execve error");
            _exit(EXIT_FAILURE);
        }
    } else {
        wait(NULL); /* Wait for the child process to finish */
    }
    return 0;
}

