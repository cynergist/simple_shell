#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;

int _printenv(void);
char *_strdup(char *string);
int cmd_read(char *s, size_t __attribute__((unused))file_stream);
char *pathfinder(char *cmd);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
void print_not_found(char *cmd);
int call_command(char *cmd_arr[]);
char *_getenv(char *var);
int _str_n_cmp(char *s1, char *s2, int n);
#endif
