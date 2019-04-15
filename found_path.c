#include "simple_shell.h"

/**
 * _found_path- found PATH in the variable global enviroment
 * and make a copy.
 * @p: storage double pointer of arguments.
 * @buffer: storage string of standar input.
 *
 * Return: the copy PATH.
 */


char *_found_path(char *buffer, char **p)
{
	int iterenv, lenght;
	char *cpypath, *cpyenv;

	for (iterenv = 0; environ[iterenv] != NULL; iterenv++)
	{
		if (_strcmp(environ[iterenv], "PATH=", 5) == 0)
		{
			break;
		}
	}

	lenght = _strlen(environ[iterenv]);
	cpyenv = malloc(sizeof(char) * lenght + 1);
	if (cpyenv == NULL)
	{
		free(buffer);
		free(p);
		exit(-1);
	}
	cpypath = _strncpy(cpyenv, environ[iterenv], lenght);
	return (cpypath);
}
