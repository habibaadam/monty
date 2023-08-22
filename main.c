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
 */
int main(int argc, char *argv[])
{
	(void)argv;

	arguments(argc);

	return (0);
}

