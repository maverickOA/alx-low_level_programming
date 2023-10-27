#include "main.h"

/**
 * get_bit - Retrieves the bit value at the given
 * index.
 *
 * @n: The number whose byte is needed
 * @index: The index for the bit needed
 *
 * Return: The bit value at @index or the value
 * -1 when the bit index specified is out of
 *  bounds
 *
 */
int get_bit(unsigned long int n, unsigned int index)
{
	if (index > 32)
	{
		return (-1);
	}
	return ((n >> index) & 1);
}

