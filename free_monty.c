#include "monty.h"
/**
 * free_resources - frees allocated memory and closes file pointer
 */
void free_resources(void)
{
	int i;

	if (args->filePointer != NULL)
		fclose(args->filePointer);

	if (args->currentLine != NULL)
		free(args->currentLine);

	if (args->toks != NULL)
	{
		for (i = 0; i < args->array_of_toks; i++)
		{
			if (args->toks[i] != NULL)
				free(args->toks[i]);
		}
		free(args->toks);
	}

	if (args->instruct_ptr != NULL)
		free(args->instruct_ptr);

	if (args != NULL)
		free(args);
}

