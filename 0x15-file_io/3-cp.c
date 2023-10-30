#include "main.h"

/**
 * main - Copy contents from a file to another.
 *
 * @argc: The number of arguments specified
 * @argv: The arguments given
 *
 * Return: 0 if the operation succeeds otherwise
 * -1
 *
 **/
int main(int argc, char *argv[])
{
	int file_from, file_to, chars_read, chars_written;
	char *str = malloc(sizeof(char) * 1024);

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	if (str == NULL)
		return (-1);
	file_from = open(argv[1], O_RDONLY);
	if (file_from == -1)
	{
		from_error(argv[1]);
	}
	file_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (file_to == -1)
	{
		to_error(argv[2]);
	}
	do {
		chars_read = read(file_from, str, 1024);
		if (chars_read == -1)
			from_error(argv[1]);
		chars_written = write(file_to, str, chars_read);
		if (chars_written == -1)
			to_error(argv[2]);
	} while (chars_read != 0);
	free(str);
	if (close(file_from) < 0)
		close_error(file_from);
	if (close(file_to) < 0)
		close_error(file_to);
	return (0);
}

/**
 * from_error - Print an error message to
 * standard error with exit code 98 when source
 * file read operation fails or file cannot
 * open.
 *
 * @str: The file the operation is performed
 * on
 */
void from_error(char *str)
{
	dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", str);
	exit(98);
}

/**
 * to_error - Print an error message to
 * standard error with exit code 99 when file
 * write operation to destination file fails.
 *
 * @str: The file the operation is performed
 * on
 */
void to_error(char *str)
{
	dprintf(STDERR_FILENO, "Error: Can't write to %s\n", str);
	exit(99);
}

/**
 * close_error - Print an error message to
 * standard error with exit code 100 when
 * the close operation fails.
 *
 * @file_descriptor: The file descriptor to the file
 * operation is performed on
 */
void close_error(int file_descriptor)
{
	dprintf(STDERR_FILENO, "Error: Can't close fd %d", file_descriptor);
	exit(100);
}
