#include "monty.h"
void stack(stack_t **stack, unsigned int tracker);
void queue(stack_t **stack, unsigned int tracker);

/**
 * stack - Set the behavior of the data structure to a stack
 * @stack: Double pointer to the top of the stack
 * @tracker: Position at which this function is called within the file
 *
 * This function sets the behavior of the data structure to work as a stack.
 * doesn't perform any direct operations on the stack, but rather sets a flag
 * in `args` structure indicating that data structure should behave as a stack.
 */
void stack(stack_t **stack, unsigned int tracker)
{
	(void) stack;
	(void) tracker;

	args->stack = 1;
}
/**
 * queue - Set the behavior of the data structure to a queue
 * @stack: Double pointer to the top of the stack
 * @tracker: Position at which this function is called within the file
 *
 * This function sets the behavior of the data structure to work as a queue.
 * doesn't perform any direct operations on the stack, but rather sets a flag
 * in `args` structure indicating the data structure should behave as a queue.
 */
void queue(stack_t **stack, unsigned int tracker)
{
	(void) stack;
	(void) tracker;

	args->stack = 0;
}

