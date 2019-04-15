#include "simple_shell.h"

/**
 * _store_args - store space for input arguments.
 * @buffer: string that contains the information entry.
 * @cont: arguments counter.
 *
 * Return: double pointer string for storage the arguments.
 */
char **_store_args(char *buffer, int *cont)
{
	char **p;
	int iter = 0;
	*cont = 0;

	while (buffer[iter] != '\0')
	{
		if (buffer[iter] == ' ' || buffer[iter] == '\n')
		{
			*cont = *cont + 1;
		}
		iter++;
	}
	*cont = *cont +  1;
	p = malloc(sizeof(char *) * (*cont));
	if (p == NULL)
	{
		exit(-1);
	}
	return (p);
}
