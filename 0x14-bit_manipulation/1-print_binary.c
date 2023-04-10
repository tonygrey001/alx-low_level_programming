#include "main.h"
#include <stdio.h>

/**
 * print_binary - a function that prints the binary representation of a number
 *
 * @n: unsigned long int
 *
 * return: void
 */

void print_binary(unsigned long int n)
{
	int binary;

	if (n >> 1)
		print_binary(n >> 1);
	/* get the last bit of the number */
	binary = n & 1;
	putchar(binary + '0');
}
