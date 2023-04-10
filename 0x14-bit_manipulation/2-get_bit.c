#include "main.h"
#include <stdio.h>

/**
 * get_bit - a function that returns the value of a bit at a given index.
 * @n: unsigned long int
 *
 * @index: the given position
 *
 * Return: value of the bit index or -1
 */

int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int binary;

	binary = (sizeof(n) * 8);
	if (index < binary)
	{
		return (((1 << index) & n) >> index);
	}
	return (-1);
}
