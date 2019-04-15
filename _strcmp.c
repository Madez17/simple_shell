#include "simple_shell.h"

/**
 * _strcmp - compare the n initials characters of two strings.
 *
 * @s1: first string.
 * @s2: second string.
 * @n: amount of characters to compare.
 *
 * Return: 1 if it's succces; 0 if not.
 */
int _strcmp(char *s1, char *s2, int n)
{
	int result;
	int cont;

	for (cont = 0; s1[cont] != '\0' && cont < n; cont++)
	{
		result = s1[cont] - s2[cont];
		if (result != 0)
		{
			return (1);
		}
	}
	return (0);
}
