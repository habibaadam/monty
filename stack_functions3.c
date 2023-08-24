#include "monty.h"

void mod_op(stack_t **stack, unsigned int tracker);
void print_top_char(stack_t **stack, unsigned int tracker);
void print_top_str(stack_t **stack, unsigned int tracker);

/**
 * mod_op - Computes the remainder of division of the second top element
 *          by the top element of the stack
 * @stack: Double pointer to the top of the stack
 * @tracker: Tracker value for error reporting
 *
 * This function calculates the remainder of division of the second top element
 * by the top element of stack. It also handles error cases when the stack is
 * too short or when the divisor (top element) is zero.
 */
void mod_op(stack_t **stack, unsigned int tracker)
{
	stack_t *first_top, *second_top;

	(void) stack;

	if (args->element_count < 2)
	{
		dprintf(2, "L%d: can't mod, stack too short\n", tracker);
		free_resources();
		exit(EXIT_FAILURE);
	}

	first_top = args->head;
	second_top = first_top->next;

	if (first_top->n == 0)
	{
		dprintf(2, "L%d: division by zero\n", tracker);
		free_resources();
		exit(EXIT_FAILURE);
	}

	second_top->n = second_top->n % first_top->n;
	pop_stack_node();

	args->element_count -= 1;
}

/**
 * print_top_char - a function that prints the character at the top of a stack
 * as long as it is not out of the range of ascii values
 * @stack: pointer to the head of the stack
 * @tracker: position where the function is called
 */

void print_top_char(stack_t **stack, unsigned int tracker)
{
	stack_t *first_top;

	(void) stack;
	/* If the stack is empty, print the error message and exit */
	if (args->head == NULL)
	{
		dprintf(2, "L%d: can't pchar, stack empty\n", tracker);
		free_resources();
		exit(EXIT_FAILURE);
	}
	first_top = args->head;
	/* If the value is not in the ascii table, print the error message */
	if (first_top->n < 0 || first_top->n > 127)
	{
		dprintf(2, "L%d: can't pchar, value out of range\n", tracker);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", first_top->n);
}

/**
 * print_top_str - prints the string of the top stack, in accordance with ascii
 * values, followed by a new line
 * @stack: pointer to the head of the stack
 * @tracker: point at which the function is called
 */
void print_top_str(stack_t **stack, unsigned int tracker)
{
	stack_t *first_top;

	(void) stack;
	(void) tracker;

	first_top = args->head;

	while (first_top != NULL && first_top->n != 0 && isascii(first_top->n))
	{
		printf("%c", first_top->n);
		first_top = first_top->next;
	}
	printf("\n");

}
