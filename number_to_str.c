#include "simple_shell.h"

/**
 * number_to_str - convert number to string.
 * @num: the number to covert.
 *
 * Return: the string of convertion.
 */

char *number_to_str(int num)
{
	char *p, *g;
	int i, j;
	int chars = 0;

	p = malloc(sizeof(char) * 10);
	if (p == NULL)
		return (NULL);

	if (num >= 0 && num <= 9)
	{
		p[0] = num + '0';
		return (p);
	}
	if (num >= 10)
	{
		g = malloc(sizeof(char) * 10);
		if (g == NULL)
			return (NULL);
		for (i = 0; (num / 10) != 0; i++)
		{
			p[i] = (num % 10) + '0';
			num /= 10;
		}
		p[i] = num + '0';
		chars += i + 1;
		for (j = 0; i >= 0; i--)
		{
			g[j] = p[i];
			j++;
		}
	}
	free(p);
	return (g);
}
