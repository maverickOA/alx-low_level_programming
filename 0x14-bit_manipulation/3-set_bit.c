#include "main.h"

/**
 * set_bit - Sets the bit value for the the given
 * number to 1.
 *
 * @n: The number whose bit will be changed
 * @index: The position of the bit to be changed
 *
 * Return: The value 1 after successfully changing
 * the bit's value otherwise -1
 *
 **/
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int bit_mask;
	int bits_for_uint = 8;

	if (index > (sizeof(index) * bits_for_uint))
	{
		return (-1);
	}
	bit_mask = 1 << index;
	*n |= bit_mask;
	return (1);
}

