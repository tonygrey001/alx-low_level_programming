#include "main.h"
#include <stdio.h>
/**
 * binary_to_uint -a function that converts a binary number to an unsigned int.
 *
 * @b: a string pointing to a string of 0 and 1 chars
 *
 * Return:the converted number, or 0
 */

unsigned int binary_to_uint(const char *b)
{
	int s;
	unsigned int i;

	i = 0;
	if (!b)
		return (0);
	for (s = 0; b[s] != '\0'; s++)
	{
		if (b[s] != '0' && b[s] != '1')
			return (0);
	}
	for (s = 0; b[s] != '\0'; s++)
	{
		i <<= 1;
		if (b[s] == '1')
			i += 1;
	}
	return (i);
}
