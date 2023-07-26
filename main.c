#include <stdio.h>
#include <stdlib.h>
#include "shell.h"
#include "prompt.h"

int main(void) {
    char *command;

    while (1) {
        display_prompt();
        command = read_command();
        if (command == NULL) {
            printf("\n");
            break; /* Handle Ctrl+D (EOF) */
        }
        if (execute_command(command) == -1) {
            perror("Error");
        }
        free(command);
    }

    return 0;
}

