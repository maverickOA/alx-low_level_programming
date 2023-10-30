#include "main.h"

int main(int argc, char *argv[])
{
	int file_descriptor, chars_count;
	char *str = malloc(sizeof(char) * 1024);

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	if (str == NULL)
		return (-1);
	file_descriptor = open(argv[1], O_RDONLY);
	if (file_descriptor == -1)
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

void from_error(char *str)
{
	dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", str);
	exit(98);
}

void to_error(char *str)
{
	dprintf(STDERR_FILENO, "Error: Can't write to %s\n", str);
	exit(99);
}

void close_error(int file_descriptor)
{
	dprintf(STDERR_FILENO, "Error: Can't close fd %d", file_descriptor);
	exit(100);
}

