#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

void cont_shell(void);
int main(void);
void exec_commd(char *commd, char **args);
void prse_exec_commd(char *value);
