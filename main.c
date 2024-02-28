#include "main.h"
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

void cont_shell(void);

int main(void)
{
	cont_shell();
	return (0);
}

void exec_commd(char *commd, char **args)
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (args[0] == NULL)
		{
			args[0] = commd;
			args[1] = NULL;
		}
		if (execve(commd, args, NULL) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(NULL);
	}
}

void prse_exec_commd(char *value)
{
	char *ptr;
	char *tkn;
	char *commd;
	char *value_cpy;
	char *args[100];
	int args_indx = 0;

	value_cpy = strdup(value);
	if (value_cpy == NULL)
	{
		perror("strdup");
		return;
	}

	tkn = strtok_r(value_cpy, " \t\n", &ptr);

	if (tkn == NULL)
	{
		free(value_cpy);
		return;
	}
	commd = tkn;
	while ((tkn = strtok_r(NULL, " \t\n", &ptr)) != NULL)
	{
		args[args_indx++] = tkn;
	}
	args[args_indx] = NULL;
	exec_commd(commd, args);
	free(value_cpy);
}


void cont_shell(void)
{
	char *prompt = "(simple_shell) $ ";
	size_t x_len = 0;
	char *line_p = NULL;
	ssize_t xy;
	int exit_sh = 0;

	while (!exit_sh)
	{
		printf("%s", prompt);
		xy = getline(&line_p, &x_len, stdin);

		if (xy == -1)
		{
			printf("\n");
			exit_sh = 1;
			continue;
		}
		if (xy <= 0)
		{
			perror("getline");
			continue;
		}
		if (line_p[xy - 1] == '\n')
		{
			line_p[xy - 1] = '\0';
		}
		if (strcmp(line_p, "exit") == 0 || strcmp(line_p, "quit")
				== 0)
		{
			printf("Ending Shell Session...\n");
			exit_sh = 1;
		}
		else
		{
			prse_exec_commd(line_p);
		}
	}
	free(line_p);
}
