#include "main.h"

unsigned int binary_to_uint(const char *b)
{
	unsigned int dec = 0;
	int b_len = 0, exponent;

	if (!_isbitsonly(b)) return (0);

	exponent = _strlen(b) - 1;
	while (b[b_len] != '\0')
	{
		dec += bit_exponent(_getbit(b[b_len]), exponent);
		b_len++;
		exponent--;
	}
	return (dec);
}

int _strlen(const char *str)
{
	int len = 0;

	while (str[len] != '\0') len++;

	return (len);
}

int bit_exponent(int bit, int index)
{
	int index_count = 0, result = 1, base = 2;

	while (index_count < index)
	{
		result *= base;
		index_count++;
	}
	return (result * bit);
}

bool _isbitsonly(const char *str)
{
	int str_index = 0;

	if (!str) return (false);

	while (str[str_index] != '\0')
	{
		if (str[str_index] != '0' && str[str_index] != '1') return (false);

		str_index++;
	}
	return (true);
}

int _getbit(char bit_str)
{
	return (bit_str == '0') ? 0 : 1;
}
