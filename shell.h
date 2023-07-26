#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

int strlength(char *string);
int strcompare(char *str_1, char *str_2);
void strcopy(char *new_str, char *old_str);
int strspace(char *string);
char **strtoken(char *line);
void free_multiarr(char **arr, int rows);
void write_to_buff(char *string);

#endif
