#include "main.h"

/**
 * _isdigit - Check if a character is a digit
<<<<<<< HEAD
 * @x: the number to be looked
 * Return: 1 for a character that will be a digit or 0
 * for any else
=======
 * @x: The number to be checked
 * Return: 1 for a character that will be a digit or 0
for any else
>>>>>>> a2e1b07eb56399765e97d0f389dc0c87716e473b
 */

int _isdigit(int x)

{
	if (x >= 48 && x <= 57)
	{
	return (1);
	}
	return (0);
}
