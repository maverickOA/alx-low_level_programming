#include "main.h"

/**
 * get_endianness - Checks the order in which bytes
 * are stored in the computer system.
 *
 * Return: 0 if endianness is big or 1 if
 * its small.
 *
 **/
int get_endianness(void)
{
	int bit_mask = 1;
	char *bits = (char *) &bit_mask;

	return (*bits);
}
