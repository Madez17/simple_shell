#include "simple_shell.h"

/**
 * handle_sigint - prevents the program from ending
 * with the keys Ctrl + c.
 *
 * @sing: signal parameter
 */

void handle_sigint(int sing)
{
	(void) sing;
	write(1, "\n", 1);
	fflush(stdout);
}
