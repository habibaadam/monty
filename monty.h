#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE
#define TOK_DELIM "\n"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <fcntl.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct FileData - Represents data related to a file.
 * @filePointer: Pointer to the file stream (FILE *).
 * @currentLine: Pointer to the current line data (char *).
 * @tracker: keeps track of lines read
 * @toks: stores words from file read
 * @array_of_toks: allocates memory for array of tokens
 * @instruct_ptr: pointer to the struct rsponsible for opcodes and its
 * function
 * @head: pointer to the head of our doubly linked list's head
 * @stack_length: length of the stack
 *
 * This structure encapsulates information related to a file, including
 * a file stream and the current line data read from that stream.
 * It is designed to manage reading lines from a file and storing their
 * associated data.
 */

typedef struct FileData
{
	FILE *filePointer;
	char *currentLine;
	unsigned int tracker;
	char **toks;
	int array_of_toks;
	instruction_t *instruct_ptr;
	stack_t *stack_head;
	unsigned int element_count;
} filedata_t;

filedata_t *args;

/* MONTY FUNCTIONS */
void check_arguments(int argc);
void init_arguments(void);
void read_file(char *file);
void tokens_maker(void);
void derive_instruction(void);
void execute_command(void);
void nonexistent_command(void);
void free_resources(void);
void free_head(stack_t *stack);
int is_valid_integer(const char *str);

/* ERROR HANDLERS */
void malloc_error(void);
void readfile_error(char *file);

/* STACK FUNCTIONS */
void push_it(stack_t **stack, unsigned int tracker);
void pall_it(stack_t **stack, unsigned int tracker) __attribute__((unused));
void pop_it(stack_t **stack, unsigned int tracker);
void pint_top(stack_t **stack, unsigned int tracker);
void swap_top(stack_t **stack, unsigned int tracker);
void add_top_two(stack_t **stack, unsigned int tracker);
void nop_nothing(stack_t **stack, unsigned int tracker);

#endif /* MONTY_H */


