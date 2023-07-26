#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "prompt.h"

void print_prompt(void) {
    char *cwd;
    cwd = getcwd(NULL, 0);
    printf("#cisfun$ ");
    fflush(stdout);
    free(cwd);
}
