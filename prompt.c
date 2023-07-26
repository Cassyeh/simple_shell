#include <stdio.h>
#include <stdlib.h>
#include "prompt.h"

char *read_command(void) {
    char *command = NULL;
    size_t bufsize = 0;
    ssize_t characters;

    characters = getline(&command, &bufsize, stdin);
    if (characters == -1) { /* Handle "end of file" condition */
        free(command);
        return NULL;
    }

    /* Remove the newline character from the command string */
    if (command[characters - 1] == '\n') {
        command[characters - 1] = '\0';
    }

    return command;
}

