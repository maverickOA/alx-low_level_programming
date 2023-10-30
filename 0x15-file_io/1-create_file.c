#include "main.h"

/**
 * create_file - Create a file with the given name.
 *
 * @filename: The name for the file
 * @text_content: The contents to be written to the file
 *
 * Return: 1 when operation completes successfully
 * otherwise -1
 *
 **/
int create_file(const char *filename, char *text_content)
{
	int file_descriptor, char_count;

	if (filename == NULL)
	{
		return (-1);
	}
	if (text_content == NULL)
	{
		char_count = 0;
	}
	else
	{
		char_count = _strlen(text_content);
	}
	file_descriptor = open(filename, O_WRONLY |
			O_CREAT | O_TRUNC, 0600);
	if (file_descriptor == -1)
	{
		return (-1);
	}
	write(file_descriptor, text_content, char_count);
	close(file_descriptor);

	return (1);
}

/**
 * _strlen - Count the total number of characters
 * in the given string.
 *
 * @str: The given string
 *
 * Return: The total number of characters found
 *
 **/
int _strlen(char *str)
{
	int index = 0;

	while (str[index] != '\0')
	{
		index++;
	}
	return (index);
}
