#include "monty.h"

void swap_top(stack_t **stack, unsigned int tracker);
void add_top_two(stack_t **stack, unsigned int tracker);
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

