#include "simple_shell.h"

/**
 * execute_ok - check the command if it's execute or not in te PATH.
 * @cpypath: the copy of PATH.
 * @p: arguments of standar input.
 * @trash: flag to specify if the command reeived is not executable.
 *
 * Return: pathname if it's executable; command alone if it's not.
 */

char *execute_ok(char *cpypath, char **p, int *trash)
{
	char *concat, *concat_slash, *result;

	result = "";
	concat = "";
	concat_slash = "";

	strtok(cpypath, "=:\n");

	while (result != NULL)
	{
		result = strtok(NULL, "=:\n");
		concat_slash = str_concat(result, "/");
		concat = str_concat(concat_slash, p[0]);
		if (access(concat, F_OK) == 0)
		{
			free(concat_slash);
			*trash = 0;
			return (concat);
		}
		free(concat_slash);
		free(concat);
	}
	return (p[0]);
}
