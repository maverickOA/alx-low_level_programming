#include "main.h"

/**
 * flip_bits - Finds the number of bits to flip to
 * convert @n to @m. No reqal conversion happens.
 *
 * @n: The original number that would be flipped
 * @m: The resulting number after flipping
 *
 * Return: The number of bits that needs to be
 * flipped
 *
 **/
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int flipped_bits = 0;
	unsigned long int xor_result = n ^ m;

	while (xor_result)
	{
		flipped_bits += xor_result & 1;
		xor_result >>= 1;
	}
	return (flipped_bits);
}

