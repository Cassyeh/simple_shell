#ifndef SHELL_H
#define SHELL_H

void display_prompt(void);
char *read_command(void);
void execute_command(char *command);

#endif /* SHELL_H */
