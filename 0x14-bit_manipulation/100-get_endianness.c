#include "main.h"
#include <stdio.h>

/**
 * get_endianness - a function that checks the endianness
 *
 * Return: 0 or 1
 */

int get_endianness(void)
{
	int i;
	char *c;

	i = 1;
	c = (char *)&i;

	return (*c);
}
