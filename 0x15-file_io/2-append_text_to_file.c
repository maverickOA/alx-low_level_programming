#include "main.h"

int append_text_to_file(const char *filename, char *text_content)
{
	int file_descriptor, chars_count;

	if (filename == NULL)
	{
		return (-1);
	}
	file_descriptor = open(filename, O_WRONLY | O_APPEND);
	if (file_descriptor == -1)
	{
		return (-1);
	}
	if (text_content != NULL)
	{
		chars_count = _strlen(text_content);
		write(file_descriptor, text_content, chars_count);
	}
	close(file_descriptor);
	return (1);
}

int _strlen(char *str)
{
	int len = 0;

	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

