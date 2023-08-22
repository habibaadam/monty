#include "monty.h"
void intil_arguments(void)
{
	filedata = malloc(sizeof(struct FileData));
	if (filedata == NULL)
		malloc_failed();

	filedata->filePointer = NULL;
	filedata->currentLine = NULL;
}

