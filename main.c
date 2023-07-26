#include <stdio.h>
#include <stdlib.h>
#include "shell.h"
#include "prompt.h"

int main(void) {
    char *command;
    int status;

    while (1) {
        print_prompt();
        command = read_command();
        if (command == NULL) {
            break; // Handle Ctrl+D (EOF)
        }
        status = execute_command(command);
        free(command);
    }

    return EXIT_SUCCESS;
}


