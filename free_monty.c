#include "monty.h"
/**
 * free_resources - frees allocated memory and closes file pointer
 */
void free_resources(void)
{
	if (args->filePointer != NULL)
		fclose(args->filePointer);

	free_toks();
	free_args();
}

/**
 * free_h - function that frees memory for the head of linked list
 */
void free_h(void)
{
	if (args->head)
		free_stack(args->head);

	args->head = NULL;
}

/**
 * free_args - function that frees memory given to args
 */

void free_args(void)
{
	if (args == NULL)
		return;
	if (args->instruct_ptr)
	{
		free(args->instruct_ptr);
		args->instruct_ptr = NULL;
	}

	free_h();

	if (args->currentLine)
	{
		free(args->currentLine);
		args->currentLine = NULL;
	}
	free(args);
}

/**
 * free_stack - a function that frees nodes of a stack
 * @head: pointer to head of stack
 */

void free_stack(stack_t *head)
{
	if (head == NULL)
		return;

	if (head->next != NULL)
	{
		free_stack(head->next);
	}

	free(head);
}

/**
 * free_toks - frees the memory allocated for tokens only
 */
void free_toks(void)
{
	int h = 0;

	if (args->toks == NULL)
		return;

	while (args->toks[h])
	{
		free(args->toks[h]);
		h++;
	}
	free(args->toks);
	args->toks = NULL;
}
