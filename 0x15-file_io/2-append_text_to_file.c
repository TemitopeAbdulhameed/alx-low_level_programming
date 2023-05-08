#include "main.h"

/**
 * _strlen - finds the lengt of  string
 * @str: pointer  the string
 *
 * Return: lengt of  string
 */
size_t _strlen(char *str)
{
	size_t i;

	for (i = 0; str[i]; i++)
		;
	return (i);
}

/**
 * append_text_to_file - append a text in the end of a file.
 * @filename: name of  file
 * @text_content: NULL terminat string to add  the end of the file
 *
 * Return: 1 on pass  and -1 on fail
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd;
	ssize_t len;

	if (filename == NULL)
		return (-1);
	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);
	if (text_content != NULL)
		len = write(fd, text_content, _strlen(text_content));
	close(fd);
	if (len == -1)
		return (-1);
	return (1);
}

