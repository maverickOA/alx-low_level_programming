#include "main.h"
/**
 *_isalpha - function thac checks for alpha
 *@c: parameter to be returned
 *Return: 1 if true
 *and 0 otherwise
 */
int _isalpha(int c)
{
	if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90))
		return (1);
	else
		return (0);
}
