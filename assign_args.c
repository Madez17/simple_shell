#include "simple_shell.h"

/**
 * assign_args - assing the rest arguments to the double
 * pointer.
 * @p: storage double pointer of arguments.
 * @cont: the amount the arguments to storage.
 *
 * Return: double pointer whit arguments.
 */

char **assign_args(char **p, int cont)
{
	int iter2 = 1;

	while (iter2 < cont)
	{
		p[iter2] = strtok(NULL, " \n\t");
		iter2++;
	}

	return (p);
}
