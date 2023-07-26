
#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>

void display_prompt(void);
char *read_command(void);
int execute_command(char *command);

#endif /* SHELL_H */
