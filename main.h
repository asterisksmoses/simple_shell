#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

void cont_shell(void);
void exec_commd(char *commd, char **args);
void prse_exec_commd(char *value);
extern char **environ;

#endif
