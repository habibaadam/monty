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


/**
 * nonexistent_command - prints error message when command is unknown
 */
void nonexistent_command(void)
{
	dprintf(2, "L%d: unknown instruction %s\n", args->tracker,
			args->toks[0]);
	if (args->filePointer == NULL)
		return;

	fclose(args->filePointer);
	args->filePointer = NULL;

	free_toks();
	free_args();
	exit(EXIT_FAILURE);

}
