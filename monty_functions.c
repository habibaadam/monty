#include "monty.h"

/**
 * check_arguments - Validate commandline arguments and provide usage message
 * if necessary.
 * @argc: The number of command-line arguments.
 *
 * This function checks the number of command-line arguments passed
 * to the program.
 * If the number of arguments is not equal to 2,
 * it prints a usage message to stderr
 * and exits the program with a failure status.
 *
 * @argc: The number of command-line arguments.
 */

void check_arguments(int argc)
{

	if (argc == 2)
		return;

	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}


/**
 * init_arguments - intializes filedata structure with NULL values
 * description - This function allocates memory for the filedata structure
 * initializes its members to NULL, and handles any memory allocation failures.
 */

void init_arguments(void)
{
	args = malloc(sizeof(filedata_t));

	if (args == NULL)
		malloc_error();

	args->filePointer = NULL;
	args->currentLine = NULL;
}

/**
 * read_file - function that gets the stream for reading from a file
 * @file: the file to be read
 */

void read_file(char *file)
{
	int descriptor;
	FILE *file_p;

	descriptor = open(file, O_RDONLY);
	if (descriptor == -1)
		readfile_error(file);

	file_p = fdopen(descriptor, "r");

	if (file_p == NULL)
	{
		close(descriptor);
		readfile_error(file);
	}
	args->filePointer = file_p;
}
