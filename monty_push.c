#include "monty.h"
/**
 * push_it - Pushes an element onto the stack.
 * @stack: Pointer to the top of the stack.
 * @tracker: Current line number being processed.
 *
 * This function pushes a new element onto the stack.
 * If there are not enough tokens or the second token is not an integer,
 * it frees resources, prints an error message, and exits with FAILURE.
 * It then allocates memory for a new stack element, assigns the value,
 * and updates the stack pointers accordingly.
 *
 * @stack: Pointer to the top of the stack.
 * @tracker: Current line number being processed.
 */
void push_it(stack_t **stack, unsigned int tracker)
{
	if (args->array_of_toks <= 1 || !is_number(args->toks[1]))
	{
		free_resources();
		dprintf(2, "L%d: usage : push integer\n", tracker);
		exit(EXIT_FAILURE);
	}

	*stack = malloc(sizeof(stack_t));
	if (*stack == NULL)
		malloc_error();
	(*stack)->next = (*stack)->prev = NULL;

	(*stack)->n = atoi(args->toks[1]);

	if (args->head != NULL)
	{
		(*stack)->next = args->head;
		args->head->prev = *stack;
	}

	args->head = *stack;
	args->stack_length += 1;
}

