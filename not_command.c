#include "simple_shell.h"

/**
 * not_command - print the message of error if the first argument
 * was not executable.
 *
 * @shell: name of executable file of the Shell.
 * @comm: command evaluated.
 * @number: number comulated of processes of the prompt.
 *
 * Return: nothing.
 */

void not_command(const char *shell, const char *comm, const char *number)
{
	static int i = 1;

	write(2, shell, _strlenconst(shell));
	write(2, ": ", 2);
	if (i < 10)
	{
		write(2, number, 1);
		i++;
	}
	else
	{
		write(2, number, _strlenconst(number));
	}
	write(2, ": ", 2);
	write(2, comm, _strlenconst(comm));
	write(2, ": not found\n", 12);
}
