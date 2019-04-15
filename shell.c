#include "simple_shell.h"

/**
 * main - Function
 * @argc: number of arguments.
 * @argv: array of pointer that storage the input
 * arguments for the prompt.
 *
 * Return: 0 if it's success, and other value if not.
 */

int main(int argc, char *argv[])
{
	char *buffer, **p;
	int cont, own_comm, count_prompt;
	(void)argc;

	count_prompt = 0;
	buffer = NULL;
	signal(SIGINT, handle_sigint);
	while (1)
	{
		count_prompt++;
		buffer = _prompt(buffer);
		p = _store_args(buffer, &cont);
		p[0] = strtok(buffer, " \n\t");
		/*0-OPCION ACCESO: _________________*/
		if (p[0] != NULL)/* 1-OWNER FUNCTIONS ------------------------------------*/
		{
			own_comm = 0;
			_exited(p, buffer);
			own_comm = _env(p);
			if (own_comm == 0)/* 2-SYSTEM FUNCTIONS ---------------------*/
			{
				p = assign_args(p, cont);
				if (access(p[0], F_OK) == 0) /*2.1- OPCION ACCESO RUTA: /bin/ls*/
				{
					execute_pathname(p);
				}
				else /* 2.2- OPCION ACCESO ONLY COMMAND: ls -----------------*/
				{
					only_command(buffer, p, argv[0], count_prompt);
				}
				wait(NULL);
			}
		}
		free(p);
	}
	return (0);
}
