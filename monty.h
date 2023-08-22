#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


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
 *
 * This structure encapsulates information related to a file, including
 * a file stream and the current line data read from that stream.
 * It is designed to manage reading lines from a file and storing their
 * associated data.
 */
struct FileData
{
	FILE *filePointer;
	char *currentLine;
} filedata_t;

extern filedata_t args;
void arguments(int argc);
void intli_arguments(void);
void malloc_failed(void);
#endif /* MONTY_H */
