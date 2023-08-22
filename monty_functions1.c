#include "monty.h"

/**
 * execute_command - executes the instructions by arguments given
 */

void execute_command(void)
{
	stack_t *ptr = NULL;

	if (args->array_of_toks == 0)
		return;

	args->instruct_ptr->f(&ptr, args->tracker);
}
