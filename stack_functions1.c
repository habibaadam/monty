#include "monty.h"
void sub_it(stack_t **stack, unsigned int tracker);
void swap_top(stack_t **stack, unsigned int tracker);
void add_top_two(stack_t **stack, unsigned int tracker);
void div_op(stack_t **stack, unsigned int tracker);
/**
 * swap_top - swaps the first two elements in a stack
 * @stack: pointer to the head of the stack
 * @tracker: pointer to the part where the function is called
 */

void swap_top(stack_t **stack, unsigned int tracker)
{
	stack_t *first_top, *second_top;

	(void) stack;

	if (args->element_count < 2)
	{
		dprintf(2, "L%d: can't swap, stack too short\n", tracker);
		free_resources();
		exit(EXIT_FAILURE);
	}

	first_top = args->head;
	second_top = first_top->next;
	first_top->next = second_top->next;

	if (first_top->next != NULL)
		first_top->next->prev = first_top;
	second_top->next = first_top;
	first_top->prev = second_top;
	second_top->prev = NULL;
	args->head = second_top;
}

/**
 * add_top_two - adds the top two members of a stack
 * @stack: pointer to the head of a stack
 * @tracker: position where function is called
 */

void add_top_two(stack_t **stack, unsigned int tracker)
{
	stack_t *first_top, *second_top;

	(void) stack;

	if (args->element_count < 2)
	{
		dprintf(2, "L%d: can't add, stack too short\n", tracker);
		free_resources();
		exit(EXIT_FAILURE);
	}

	first_top = args->head;
	second_top = first_top->next;

	second_top->n = first_top->n + second_top->n;
	pop_stack_node();

	args->element_count -= 1;
}
/**
 * sub_it - Subtracts the value of the top element from the second top element
 * @stack:Double pointer to the top of the stack
 * @tracker: Tracker value for error reporting
 *
 * This function subtracts the value of top element from the second top element
 * of the stack. It also handles error cases when the stack is too short.
 */
void sub_it(stack_t **stack, unsigned int tracker)
{
	stack_t *first_top, *second_top;

	(void) stack;

	if (args->element_count < 2)
	{
		dprintf(2, "L%d: can't sub, stack too short\n", tracker);
		free_resources();
		exit(EXIT_FAILURE);
	}

	first_top = args->head;
	second_top = first_top->next;

	second_top->n = second_top->n - first_top->n;
	pop_stack_node();

	args->element_count -= 1;
}
/**
 * div_op - Divides the second top element by the top element of the stack
 * @stack: Double pointer to the top of the stack
 * @tracker: Tracker value for error reporting
 *
 * This function divides the value of the second top element by the top element
 * of stack. It also handles error cases when the stack is too short or when
 * the divisor (top element) is zero.
 */
void div_op(stack_t **stack, unsigned int tracker)
{
	stack_t *first_top, *second_top;

	(void) stack;

	if (args->element_count < 2)
	{
		dprintf(2, "L%d: can't div, stack too short\n", tracker);
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

	second_top->n = second_top->n / first_top->n;
	pop_stack_node();

	args->element_count -= 1;
}
