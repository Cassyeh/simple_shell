#ifndef SHELL_H
#define SHELL_H

/*-----------------------Include_Libraries-----------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stddef.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdarg.h>
/*-------------------Define variables for getline & Alias------*/
#define BUFSIZE 1024

extern char **environ;

/*-------------------------Prototypes--------------------------*/
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *_reaad(void);
void _memcpy(void *newptr, const void *ptr, unsigned int size);
int _atoi(char *s);
ssize_t get_line(char **lineptr, size_t *n, FILE *stream);
void bring_line(char **lineptr, size_t *n, char *buffer, size_t j);
int prompt(void);
void _print_num(int n);
char *_strtok(char *str, const char *dlm);
char **split(char *buff);
size_t _strlen(const char *str);
char *_strdup(const char *s);
char *_strcpy(char *des, const char *src);
char *_strcat(char *dstn, char *src);
int _strncmp(const char *s1, const char *s2, size_t n);
int exe_cmd(char **argv);
char *get_path(char *cmd);
char *get_env(const char *nam);
int _env(void);
int _print_str(char *str);
int _putchar(char c);
void check_input(char **splited_input);
int _echoo(char **arg);
char *_con_cat(char *tmp, char **arg, char *tok);
int _PATHstrcmp(const char *s1, const char *s2);
int _proc_fork(char **arg, char *buff, char *fpb);
int _splitPATH(char *str);
char *_pathfbuff(char **arg, char *PATH, char *copy);
int checks(char **arg, char *buff, int exitstat);
void _puts(char *str);
char *_memset(char *s, char b, unsigned int n);
int _splitstring(char *s);
/*---------Alias function--*/
int _snprint(char *str, size_t size, const char *format, ...);
char *_strncpy(char *dst, const char *src, size_t n);

#endif
