#include "simple_shell.h"

/**
 * _exited - the function built-in that implement the command "exit"
 * in the shell.
 * @p: storage double pointer of arguments.
 * @buffer: storage string of standar input.
 *
 * Return: nothing.
 */

void _exited(char **p, char *buffer)
{
	if ((_strlen(p[0]) - 4) == 0)
	{
		if (_strcmp(p[0], "exit", 4) == 0)
		{
			free(buffer);
			free(p);
			exit(-1);
		}
	}
}
