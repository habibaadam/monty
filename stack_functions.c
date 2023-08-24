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
		printf("%d\n", fornow->n);
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
/**
 * push_it - Pushes an integer onto the stack or queue
 * @stack: Double pointer to the top of the stack/queue
 * @tracker: Position at which this function is called within the file
 *
 *function pushes an integer onto the stack or queue based on behavior defined.
 *handles error cases and performs necessary memory allocation and assignments.
 */
void push_it(stack_t **stack, unsigned int tracker)
{
	if (args->array_of_toks <= 1 || !is_valid_integer(args->toks[1]))
	{
		free_args();
		dprintf(2, "L%d: usage: push integer\n", tracker);
		exit(EXIT_FAILURE);
	}

	*stack = malloc(sizeof(stack_t));
	if (*stack == NULL)
	{
		malloc_error();
		free_resources();
	}

	(*stack)->next = (*stack)->prev = NULL;

	(*stack)->n = atoi(args->toks[1]);

	if (args->stack)
	{
		if (args->head == NULL)
		{
			args->head = *stack;
		}
		else
		{
			(*stack)->next = args->head;
			args->head->prev = *stack;
			args->head = *stack;
		}
	}
	else
	{
		if (args->head == NULL)
		{
			args->head = *stack;
		}
		else
		{
			stack_t *first_node = args->head;

			while (first_node->next)
				first_node = first_node->next;

			first_node->next = *stack;
			(*stack)->prev = first_node;
		}
	}
	args->element_count += 1;
}

/**
 * pop_it - Removes the top element from the stack
 * @stack: Pointer to a pointer to the stack
 * @tracker: Line number tracker for error reporting
 *
 * This function removes the top element from the stack and updates the stack.
 * If the stack is empty, it prints an error message and exits.
 */
void pop_it(stack_t **stack, unsigned int tracker)
{
	(void) stack;

	if (args->head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", tracker);
		free_resources();
		exit(EXIT_FAILURE);
	}

	pop_stack_node();
	args->element_count -= 1;

}

