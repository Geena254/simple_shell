#ifndef SHELL_H
#define SHELL_H
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

void prompt(char **av, char **env);

/* strings manipulation */
int _strlen(char *s);


#endif /* SHELL_H */
