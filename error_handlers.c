#include "monty.h"

/**
 * malloc_error - handles and prints error message  if malloc fails
 */
void malloc_error(void)
{
	fprintf(stderr, "Error: malloc fail\n");
	exit(EXIT_FAILURE);
}

/**
 * readfile_error - function that prints an error message when opening or
 * reading from a file fails
 * @file: pointer to the file to be read and opened
 */

void readfile_error(char *file)
{
	fprintf(stderr, "Error: Can't open file %s\n", file);
	exit(EXIT_FAILURE);
}

