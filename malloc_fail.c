#include "monty.h"
/**
 * malloc_failed - handles some errors if malloc fails
 */
void malloc_failed(void)
{
	fprintf(stderr, "Error: malloc fail\n");
	intli_arguments();
	exit(EXIT_FAILURE);
}
