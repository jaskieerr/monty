#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>
#include <string.h>

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

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

void pall(stack_t **stack, unsigned int line_number);
void push(stack_t **new_stack, __attribute__((unused))unsigned int ln);
int main(int argc, char *argv[]);
void file_oppen(char *file);
void readd(FILE *fptr);
int tokenizea(char *buffea, int line_num, int format);
void call_fun(op_func fun, char *op, char *val, int ln, int sorq);
void findd(char *opcode, char *val, int line_num, int sorq);
void dealloc(void);
void out_error(int erroru, ...);
stack_t *makenode(int n);
void enqueue(stack_t **q, __attribute__((unused))unsigned int linu);
void pint(stack_t **stack, unsigned int line_numbea);
void outerr(int anerroru, ...);
void nop(stack_t **stack, unsigned int lnn);
void pop(stack_t **stack, unsigned int line_numbea);

#endif
