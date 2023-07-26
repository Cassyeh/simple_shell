#include <stdio.h>
#include "shell.h" /* Include the shell header file*/

int main(void) {
    char *command;

    while (1) {
        printf("#cisfun$ ");
        command = read_command(); /* Call the read_command function from shell.c*/
        execute_command(command);
        free(command);
    }

    return (0);
}
