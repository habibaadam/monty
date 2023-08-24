#include "monty.h"

/**
 * check_arguments - Validate commandline arguments and provide usage message
 * if necessary.
 * @argc: The number of command-line arguments.
 *
 * This function checks the number of command-line arguments passed
 * to the program.
 * If the number of arguments is not equal to 2,
 * it prints a usage message to stderr
 * and exits the program with a failure status.
 *
 * @argc: The number of command-line arguments.
 */

void check_arguments(int argc)
{

	if (argc == 2)
		return;

	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}


/**
 * init_arguments - intializes filedata structure with NULL values
 * description - This function allocates memory for the filedata structure
 * initializes its members to NULL, and handles any memory allocation failures.
 */

void init_arguments(void)
{
	args = malloc(sizeof(filedata_t));

	if (args == NULL)
		malloc_error();
	args->instruct_ptr = malloc(sizeof(instruction_t));
	if (args->instruct_ptr == NULL)
		malloc_error();

	args->filePointer = NULL;
	args->currentLine = NULL;
	args->tracker = 0;
	args->array_of_toks = 0;
	args->head = NULL;
	args->element_count = 0;
}

/**
 * read_file - function that gets the stream for reading from a file
 * @file: the file to be read
 */

void read_file(char *file)
{
	int descriptor;
	FILE *file_p;

	descriptor = open(file, O_RDONLY);
	if (descriptor == -1)
		readfile_error(file);

	file_p = fdopen(descriptor, "r");

	if (file_p == NULL)
	{
		close(descriptor);
		readfile_error(file);
	}
	args->filePointer = file_p;
}

/**
 * tokens_maker - function that splits words according to specified delimiter
 */
void tokens_maker(void)
{
	int h = 0;
	char *token = NULL, *line_dup = NULL;

	line_dup = strdup(args->currentLine);
	args->array_of_toks = 0;
	token = strtok(line_dup, TOK_DELIM);

	while (token != NULL)
	{
		args->array_of_toks += 1;
		/*printf("Token %d: %s\n", h, token);*/
		token = strtok(NULL, TOK_DELIM);
	}

	args->toks = malloc(sizeof(char *) * (args->array_of_toks + 1));
	strcpy(line_dup, args->currentLine);
	token = strtok(line_dup, TOK_DELIM);

	/*h = 0; */

	while (token != NULL)
	{
		args->toks[h] = malloc(sizeof(char) * (strlen(token) + 1));
		if (args->toks[h] == NULL)
			malloc_error();
		strcpy(args->toks[h], token);
		/*printf("Token %d: %s\n", h, args->toks[h]);*/
		token = strtok(NULL, TOK_DELIM);
		h++;
	}
	args->toks[h] = NULL;
	free(line_dup);
}

/**
 * derive_instruction - function that matches or finds the first instruction
 * based on the very first token obtained
 */

void derive_instruction(void)
{
	int m = 0;
	instruction_t commands[] = {
		{"push", &push_it}, {"pall", &pall_it},
		{"pint", &pint_top}, {"nop", &nop_nothing},
		{"pop", &pop_it}, {"swap", &swap_top},
		{"add", &add_top_two}, {"sub", &sub_it},
		{"div", &div_op}, {"mul", &mul_op},
		{"mod", &mod_op},
		{NULL, NULL}
	};

	if (args->array_of_toks == 0)
		return;
	if (args->toks[0][0] == '#')
	{
		args->instruct_ptr->opcode = "nop";
		args->instruct_ptr->f = nop_nothing;
		return;
	}

	for (; commands[m].opcode != NULL; m++)
	{
		if (strcmp(commands[m].opcode, args->toks[0]) == 0)
		{
			args->instruct_ptr->opcode = commands[m].opcode;
			args->instruct_ptr->f = commands[m].f;
			return;
		}
	}
	nonexistent_command();
}

