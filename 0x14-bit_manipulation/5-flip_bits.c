#include "main.h"
#include <stdio.h>

/**
 * flip_bits - a function that changes number.
 *
 * @n: first unsigned long int
 * @m: second unsigned long int
 *
 * Return: number of bits you would need to flip to get from one number
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int diff = 0, result = 0;

	diff = n ^ m;
	while (diff)
	{
		if (diff & 1)
			result++;
		diff = diff >> 1;
	}
	return (result);
}
