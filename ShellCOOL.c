#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "main.h"


int main(void)
{
    char *buffer;
    size_t bufsize = 1024; // Adjust this buffer size as needed
    ssize_t characters;

    buffer = (char *)malloc(bufsize * sizeof(char));
    if (!buffer)
    {
        perror("malloc error");
        return (EXIT_FAILURE);
    }

    while (1)
    {
        printf("#cisfun$ ");
        characters = getline(&buffer, &bufsize, stdin);
        if (characters == -1) // Handle "end of file" condition
        {
            printf("\n");
            break;
        }

        /* Parse the user input and get the command */

        /* Use execve and fork to execute the command */

        /* Handle command not found error */

        /* Continue to the next prompt */
    }

    free(buffer);
    return (EXIT_SUCCESS);
}
