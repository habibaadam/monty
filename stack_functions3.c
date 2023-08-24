#include "monty.h"

void mod_op(stack_t **stack, unsigned int tracker);

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

