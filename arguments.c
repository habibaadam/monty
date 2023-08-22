#include "monty.h"
void arguments(int argc)
{

	if (argc == 2)
		return;

	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}
