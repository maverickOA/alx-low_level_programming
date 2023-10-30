#include "main.h"

ssize_t read_textfile(const char *filename, size_t letters)
{
    int file_descriptor;
    ssize_t chars_read, chars_written;
    char *buffer;

    if (filename == NULL)
        return (0);

    buffer = malloc(sizeof(char) * letters);
    if (buffer == NULL)
        return (0);

    file_descriptor = open(filename, O_RDONLY);
    if (file_descriptor == -1)
    {
        free(buffer);
        return (0);
    }

    chars_read = read(file_descriptor, buffer, letters);
    close(file_descriptor);

    if (chars_read == -1)
    {
        free(buffer);
        return (0);
    }

    chars_written = write(STDOUT_FILENO, buffer, chars_read);
    free(buffer);

    if (chars_written == -1 || chars_written != chars_read)
        return (0);

    return (chars_read);
}

