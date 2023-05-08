/*
 * File: 0-read_textfile.c
 * Auth: Abdulhameed Aishat
 */
#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - Reads the  text file and prints to POSIX stdout.
 * @filename:  pointer of  name of  file.
 * @letters:  number of letter the
 *           functions should read an print.
 *
 * Return:  the function fail or filename is NULL - 0.
 *         O/w - the actual numbers of byte the function  read and prints.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t o, r, w;
	char *buffer;

	if (filename == NULL)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
		return (0);

	o = open(filename, O_RDONLY);
	r = read(o, buffer, letters);
	w = write(STDOUT_FILENO, buffer, r);

	if (o == -1 || r == -1 || w == -1 || w != r)
	{
		free(buffer);
		return (0);
	}

	free(buffer);
	close(o);

	return (w);
}


