#include "monty.h"
/**
 *arguments -Validate commandline arguments provide usage message if necessary.
 *@argc: The number of command-line arguments.
 *
 *description- function checks the number of command-line arguments passed to
 *program. If the number of arguments is not equal to 2,
 *it prints a usage message to stderr, exits the program with a failure status.
 *
 * @argc: The number of command-line arguments.
 */
void arguments(int argc)
{

	if (argc == 2)
		return;

	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}
