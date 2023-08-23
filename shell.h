#ifndef SHELL_H
#define SHELL_H
#include <unistd.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>

extern char **environ;
void prompt(char **env);
void handle_path(char **argv);
void handl_exit(char *string);
char *_getenv(const char *name);
void print_environment(char **env);
ssize_t my_getline(char **lineptr, size_t *m, FILE *stream);
void execute_command(char **argv, char **env);
void tokenize_input(char *input, char **argv);
void remove_newline(char *input);

/* strings manipulation */
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strncpy(char *dest, char *src, size_t n);
int _strcmp(char *s1, char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strcat(char *dest, char *src);

#endif /* SHELL_H */
