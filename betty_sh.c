#include "main.h"

/**
 * main - Entry point of the shell program
 * Return: 0 upon success
 */

int main(void)
{
	char *prompt = "(simple_shell) $ ";
	char commd[100];
	char *str;
	int x;

	for (x = 1; x; x++)
	{
		printf("%s\n", prompt);
		str = fgets(commd, sizeof(commd), stdin);

		if (str == NULL)
		{
			printf("\n");
			break;
		}
		printf("Your Input: %s", commd);
	}
	return (0);
}
