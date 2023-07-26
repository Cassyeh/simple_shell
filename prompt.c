#include <stdio.h>
#include <stdlib.h>
#include "prompt.h"

void display_prompt(void) {
    printf("#cisfun$ ");
}

char *read_command(void) {
    char *command = NULL;
    size_t bufsize = 0; /* getline will allocate memory */
    ssize_t characters;

    characters = getline(&command, &bufsize, stdin);
    if (characters == -1) /* Handle "end of file" condition */
        return NULL;

    return command;
}

