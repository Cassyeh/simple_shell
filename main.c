#include <stdlib.h>
#include "main.h"

extern char **environ;

int main(void)
{
    char *command;

    while (1)
    {
        display_prompt();
        command = read_command();

        if (*command != '\0')
            execute_command(command);

        free(command);
    }

    return 0;
}
