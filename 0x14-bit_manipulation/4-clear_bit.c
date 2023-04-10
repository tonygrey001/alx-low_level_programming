#include "main.h"
#include <stdio.h>

/**
 * clear_bit - function sets the value of a bit to 0 at a given index.
 * @n: unsigned long int
 *
 * @index: a given position
 *
 * Return: 1 or -1
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int binary;

	binary = (sizeof(*(n)) * 8);
	if (index < binary)
	{
		*(n) = (~(1 << index) & *(n));
		return (1);
	}
	return (-1);
}
