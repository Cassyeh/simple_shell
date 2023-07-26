#include "shell.h"

/**
* main - int function
* Return: Null
*/

int main(void)
{
	char *fpb = NULL, *copy = NULL, *buff = NULL;
	char *PATH = NULL;
	int exitstat = 0;
	char **arg;

	signal(SIGINT, SIG_IGN);
	PATH = get_env("PATH");
	if (PATH == NULL)
		return (-1);
	while (1)
	{
		arg = NULL;
		prompt();
		buff = _reaad();

		if (*buff != '\0')
		{
			arg = split(buff);
			if (arg == NULL)
			{
				free(buff);
				continue;
			}
			fpb = _pathfbuff(arg, PATH, copy);

			if (checks(arg, buff, exitstat) == 1)
				continue;
			exitstat = _proc_fork(arg, buff, fpb);
		}
		else
			free(buff);
	}

	return (0);
}
