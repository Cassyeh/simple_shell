#include "shell.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_INPUT_SIZE 1024
#define MAX_TOKENS 64
#define DELIMITERS " \t\n\r\a"

/* Implement utility functions and other function prototypes as needed */

int main() {
    char *input;
    char **args;

    do {
        _putchar('#');
        _putchar('c');
        _putchar('i');
        _putchar('s');
        _putchar('f');
        _putchar('u');
        _putchar('n');
        _putchar('$');
        _putchar(' ');

        input = read_input();
        if (input == NULL) {
            /* Handle Ctrl+D (EOF)*/
            _putchar('\n');
            break;
        }
        
        args = tokenize_input(input);
        if (args[0] != NULL) {
            if (strcmp(args[0], "exit") == 0) {
                /*Handle 'exit' command*/
                break;
            } else if (strcmp(args[0], "cd") == 0) {
                /* Handle 'cd' command*/
                if (args[1] != NULL) {
                    if (chdir(args[1]) != 0) {
                        perror("cd error");
                    }
                }
            } else {
                /*Execute external command*/
                execute_command(args);
            }
        }

        free(input);
        free(args);
    } while (1);

    return 0;
}
