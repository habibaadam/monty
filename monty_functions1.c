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
/**
 * is_valid_integer - Checks if a given string represents a valid integer.
 * @str: The input string to be checked.
 *
 * Return: 1 if the string is a valid integer, 0 otherwise.
 */
int is_valid_integer(const char *str)
{
	if (str == NULL || *str == '\0')
	{
		return (0);
	}

	if (*str == '-')
	{
		str++;
	}

	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
		{
			return (0);
		}
		str++;
	}

	return (1);
}

