#include "simple_shell.h"

/**
 * _prompt - get arguments of standar input.
 * @buffer: storage string.
 *
 * Return: return of the strorage string.
 */

char *_prompt(char *buffer)
{
	ssize_t characters;
	size_t sizebuf = 120;

	/*write(1, "#cisfun$ ", 9);*/
	characters = getline(&buffer, &sizebuf, stdin);
	if (characters == EOF)
	{
		write(1, "\n", 1);
		free(buffer);
		exit(0);
	}
	return (buffer);

}
