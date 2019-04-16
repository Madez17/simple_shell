#include "simple_shell.h"

/**
 * _env - the function built-in that implement the command "env"
 * in the shell.
 * @p: storage double pointer of arguments.
 *
 * Return: 1 if it's succces; 0 if is not.
 */
int _env(char **p)
{
	int iterenv;
	int lenght;

	if ((_strlen(p[0]) - 3) >= 0)
	{
		if (_strcmp(p[0], "env", 3) == 0)
		{
			for (iterenv = 0; environ[iterenv] != NULL; iterenv++)
			{
				lenght = _strlen(environ[iterenv]);
				write(1, environ[iterenv], lenght);
				write(1, "\n", 1);
			}
			status = 0; 
			return (1);
		}
	}
	return (0);
}
