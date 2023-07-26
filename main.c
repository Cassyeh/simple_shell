#include <stdio.h>
#include <stdlib.h>
#include "shell.h"
#include "prompt.h"

int main(void) 
{
	return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include "shell.h"

int main(void) {
	char *command;
	int status;

	display_prompt();

	while ((command = read_command()) != NULL) {
		status = execute_command(command);
			free(command);
			display_prompt();
	}

	printf("\n");
	return 0;
}
