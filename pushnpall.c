#include "monty.h"


/**
 * push - Adds a node stack
 * @new_stack: neww added node ptr
 * @op_line_num: opcode line numbea
 */
void push(stack_t **new_stack, __attribute__((unused))unsigned int op_line_num)
{
	stack_t *Ptr;

	if (new_stack == NULL || *new_stack == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_stack;
		return;
	}
	Ptr = head;
	head = *new_stack;
	head->next = Ptr;
	Ptr->prev = head;
}




/**
 * pall - Adds node to stack
 * @stack: double ptr to stack_t
 * @line_number: linr ehrtr is the upcode located
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *Ptr;

	(void) line_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	Ptr = *stack;
	while (Ptr != NULL)
	{
		printf("%d\n", Ptr->n);
		Ptr = Ptr->next;
	}
}
