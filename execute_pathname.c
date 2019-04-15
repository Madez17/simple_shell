#include "simple_shell.h"

/**
 * execute_pathname - execute when the command is for path
 * @p: arguments of standar input.
 *
 * Return: nothing.
 */

void execute_pathname(char **p)
{
	char *concat = p[0];

	if (fork() == 0)
	{
		execve(concat, p, NULL);
	}
}
