#include "monty.h"

/**
 * main - Entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array of strings containing the command-line arguments.
 *
 *Description - function is entry point of program. It checks the command-line
 * arguments and ensures that correct number of arguments are provided. If the
 * number of arguments is incorrect,prints usage message and exits the program.
 * Otherwise, it continues with program execution.
 *
 * @argc: The number of command-line arguments.
 * @argv: An array of strings containing the command-line arguments.
 * Return: The exit status of the program.
 *
 */
int main(int argc, char *argv[])
{
	size_t m = 0;
	ssize_t read_args;

	check_arguments(argc);
	init_arguments();

	/*printf("Input file: %s\n", argv[1]);*/
	read_file(argv[1]);

	while ((read_args = getline(&args->currentLine, &m,
					args->filePointer)) != -1)
	{
		args->tracker += 1;
		tokens_maker();
		derive_instruction();
		execute_command();
		free_toks();
	}
	/* closing link to file */

	if (args->filePointer == NULL)
		return (0);
	fclose(args->filePointer);
	args->filePointer = NULL;

	/* Free allocated resources before exiting */
	free_args();

	return (0);
}


