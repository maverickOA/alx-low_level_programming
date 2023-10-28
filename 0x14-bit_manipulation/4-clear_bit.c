#include "main.h"

/**
 * clear_bit - Set the given index bit value
 * to 0 for the given number.
 *
 * @n: The given number
 * @index: The position for the bit to be changed
 *
 * Return: The value 1 after successfully changing
 * the bit's value otherwise -1
 *
 **/
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int bit_mask;
	int bits_for_uint = 8;

	if (index > (sizeof(int) * bits_for_uint))
	{
		return (-1);
	}
	bit_mask = 1 << index;
	*n &= ~(bit_mask);
	return (1);
}
