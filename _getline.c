#include <stdio.h>
#include <stdlib.h>
/**
 * _getline - Custom implementation of the getline function.
 * @lineptr: A pointer to the buffer storing the line read.
 * @n: A pointer to the size of the buffer.
 * @stream: The stream to read from.
 *
 * Return: The number of characters read (including newline),
 * or -1 if an error occurs or end of file is reached.
 */
size_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	size_t bufsize = 128; /* Initial buffer size */
	int c;
	size_t i = 0;

	if (lineptr == NULL || n == NULL || stream == NULL)
		return (-1); /* Invalid input parameters */
	if (*lineptr == NULL)
	{
		*lineptr = (char *)malloc(bufsize * sizeof(char));
		if (*lineptr == NULL)
		{
			return (-1); /* Memory allocation failure */
		}
		*n = bufsize;
	}
	while ((c = fgetc(stream)) != EOF)
	{
		if (i == *n - 1)
		{
			bufsize *= 2;
			*lineptr = (char *)realloc(*lineptr, bufsize);
			if (*lineptr == NULL)
			{
				return (-1); /* Memory reallocation failure */
			}
			*n = bufsize;
		}
		(*lineptr)[i++] = (char)c;
		if (c == '\n')
		{
			break; /* Line read successfully */
		}
	}
	if (i == 0 && c == EOF)
	{
		return (-1); /* No characters read and end of file reached */
	}
	(*lineptr)[i] = '\0'; /* Null-terminate the string */
	return (i); /* Number of characters read (including newline) */
}
