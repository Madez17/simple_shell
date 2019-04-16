#include "simple_shell.h"

/**
 * only_command - check the command if it's execute or not in the PATH.
 * If it's succces, the command is execute in the children procces; if not
 * show error.
 * @buffer: the storage string of strandar input.
 * @p: arguments of standar input.
 * @name_shell: first argument of main.
 * @count_prompt: amount proccess of getline.
 *
 * Return: nothing.
 */

void only_command(char *buffer, char **p, char *name_shell, int count_prompt)
{
	int trash;
	char *cpypath, *concat, *number_prompt;

	trash = 1;

	cpypath = _found_path(buffer, p);
	if(cpypath == NULL)
	{
		number_prompt = number_to_str(count_prompt);
		not_command(name_shell, p[0], number_prompt);
	}
	else
	{
		concat = execute_ok(cpypath, p, &trash);

		if (trash == 0)
		{
			if (fork() == 0)
			{
				execve(concat, p, NULL);
			}
			free(cpypath);
			free(concat);
		}
		else
		{
			if(execve(p[0], p, NULL) == -1)
			{
				number_prompt = number_to_str(count_prompt);
				not_command(name_shell, p[0], number_prompt);
			}
			free(cpypath);
			free(number_prompt);
		}
	}
}
