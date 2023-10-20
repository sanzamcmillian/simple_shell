#include "shell.h"

/**
 *_getline: Reads an entire line from a stream, storing the address of the buffer
 *containing the next into *lineptr. if *lineptr is NULL, a new buffer will  be allocated
 *in either case, *lineptr will be updated to point to the buffer.
 *the buffer size is stored in *n.
 *
 *
 *@param lineptr: Pointer to the buffer.
 *@param n: pointer to the buffer size.
 *@param stream: the input stream to read from.
 *
 *@return: the number of characters read, ot (-1) on faillure.
 */

ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	const size_t BUFFER_SIZE = 128;
	const double GROWTH_FACTOR = 1.5;
	const size_t SHRINK_THRESHOLD = 512;
	size_t num_read = 0;
	int c;
	char *new_buffer = NULL;

	if (!lineptr || !n)
	{
		perror("Invalid arguments to getline.\n");
		return (-1);
	}

	if (!*lineptr || *n == 0)
	{
		*lineptr = malloc(BUFFER_SIZE);
		if (!*lineptr)
		{
			perror("Memory allocation failure");
			return (-1);
		}
		*n = BUFFER_SIZE;
	}

	while ((c = fgetc(stream)) != EOF)
	{
		if (num_read + 1 >= *n)
		{
			*n *= GROWTH_FACTOR;
			new_buffer = realloc(*lineptr, *n);
			if (!new_buffer)
			{
				perror("Memory reallocation failure");
				return (-1);
			}
			*lineptr = new_buffer;
		}

		(*lineptr)[num_read++] = c;

		if (c == '\n')
			break;

	}

	(*lineptr)[num_read] = '\0';

	if (num_read == 0 && c == EOF)
		return (-1);

	if (*n - num_read > SHRINK_THRESHOLD)
	{
		char *new_buffer = realloc(*lineptr, num_read + 1);
		if (new_buffer)
		{
			*lineptr = new_buffer;
			*n = num_read + 1;
		}
	}

	return (num_read);
}
