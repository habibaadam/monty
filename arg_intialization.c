#include "monty.h"
/**
 * intil_arguments - intializes filedata structuew with NULL values
 * descripition - This function allocates memory for the filedata structure,
 * initializes its members to NULL, and handles any memory allocation failures.
 */
void intil_arguments(void)
{
	filedata = malloc(sizeof(struct FileData));
	if (filedata == NULL)
		malloc_failed();

	filedata->filePointer = NULL;
	filedata->currentLine = NULL;
}

