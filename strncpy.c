#include "simple_shell.h"

/**
 * _strncpy - copy a string until lenght n.
 * @dest: dest array.
 * @src: source array.
 * @n: length of copy.
 *
 * Return: copy string.
 */
char *_strncpy(char *dest, char *src, int n)
{
	int cont;

	for (cont = 0; src[cont] != '\0' && cont < n; cont++)
	{
		dest[cont] = src[cont];
	}
	for (; cont < n; cont++)
		dest[cont] = '\0';
	return (dest);
}
