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
	stack_t *fornow;

	if (args->head == NULL)
		return;

	(void) tracker;
	(void) stack;

	fornow = args->head;
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
	(void) stack;

	if (args->head == NULL)
	{
		dprintf(2, "L%d: can't pint, stack empty\n", tracker);
		free_resources();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", args->head->n);
}

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