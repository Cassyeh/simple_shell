#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>

/*-------------------------Prototypes--------------------------*/
int _putchar(char c);
void some_function(void);

void display_prompt(void);
char *read_command(void);
void execute_command(char *command);
void print_error(char *command);

#endif /* MAIN_H */
