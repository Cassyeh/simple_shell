#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "shell.h"

void execute_command(char *command) {
    pid_t pid;
    char **args = malloc(2 * sizeof(char *));

    if (args == NULL) {
        perror("malloc error");
        _exit(EXIT_FAILURE);
    }

    args[0] = command;
    args[1] = NULL;

    pid = fork();

    if (pid == -1) {
        perror("fork error");
        free(args);
        _exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        if (execve(command, args, NULL) == -1) {
            perror(command);
            free(args);
            _exit(EXIT_FAILURE);
        }
    } else {
        wait(NULL);
    }

    free(args);
}

