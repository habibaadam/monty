#include "monty.h"

void push_it(stack_t **stack, unsigned int tracker);
void pall_it(stack_t **stack, unsigned int tracker);
void pop_it(stack_t **stack, unsigned int tracker);
void nop_nothing(stack_t **stack, unsigned int tracker);
void pint_top(stack_t **stack, unsigned int tracker);


/**
 * pall_it - function that prints all elements in the stack
 * @stack: pointer to the stack
 * @tracker: point at which the function was called
 */

void pall_it(stack_t **stack, unsigned int tracker)
{

	stack_t *fornow = *stack;

	if (fornow == NULL)
		return;

	(void) tracker;

	while (fornow != NULL)
	{
		printf("%d\n ", fornow->n);
		fornow = fornow->next;
	}
}

/**
 * nop_nothing - a function that does nothing
 * @stack: pointer to the head of stack
 * @tracker: point at which this function is called
 */
void nop_nothing(stack_t **stack, unsigned int tracker)
{
	(void) stack;
	(void) tracker;
}

/**
 * pint_top - a function that prints the top element of a stack
 * @stack: pointer to the head of the stack
 * @tracker: point where the function is called
 */

void pint_top(stack_t **stack, unsigned int tracker)
{
	if (*stack == NULL)
	{
		dprintf(2, "L%d: can't pint, stack empty\n", tracker);
		free_resources();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
