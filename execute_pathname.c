#include "simple_shell.h"

/**
 * execute_pathname - execute when the command is for path
 * @p: arguments of standar input.
 * @name_shell: name of the program.
 * @count_prompt: count the iteration.
 * @status: exit state of program.
 * Return: nothing.
 */

void execute_pathname(char **p, char *name_shell, int count_prompt,
int *status)
{
	char *concat = p[0];
	char *pathname = *p;
	char *number_prompt;
	int i, res;
	pid_t pid;

	for (i = 0; pathname[i] != '\0'; i++)
	{
		if (pathname[i] == '/')
		{
			pid = fork();
                        if (pid == 0)
                        {
                                execve(concat, p, NULL);
                        }
                        pid = waitpid(pid, &res, 0);
                        if (WIFEXITED(res))
                                *status = WEXITSTATUS(res);
			return;
		}
	}
	number_prompt = number_to_str(count_prompt);
	not_command(name_shell, p[0], number_prompt);
	*status = 127;
	free(number_prompt);
}
