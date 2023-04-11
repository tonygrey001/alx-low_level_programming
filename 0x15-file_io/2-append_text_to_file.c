#include "main.h"
#include <stdio.h>

/**
 * append_text_to_file - function that appends a text at the end of a file.
 *
 * @filename: name of the file
 *
 * @text_content: NULL terminated string to add at the end of the file
 *
 * Return: 1 or -1
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int count, len = 0, fd, i;

	if (filename == NULL)
		return (-1);

	fd = open(filename, 2 | O_APPEND, 0600);
	if (fd == -1)
		return (-1);
	if (text_content == NULL)
		return (1);
	for (i = 0; text_content[i]; i++)
		len++;
	count = write(fd, text_content, len);
	if (count == -1)
	{
		close(fd);
		return (-1);
	}
	close(fd);

	return (1);
}
