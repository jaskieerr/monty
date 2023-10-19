#include "monty.h"

/**
 * nop - does jackshit
 * @stack: top node double pointer
 * @lnn: line number
 */
void nop(stack_t **stack, unsigned int lnn)
{
	(void)stack;
	(void)lnn;
}

/**
 * pop - remove the top of stack
 * @stack: top of the stack double pointer
 * @line_numbea: line numbea obviously
 */
void pop(stack_t **stack, unsigned int line_numbea)
{
	stack_t *Ptr;

	if (stack == NULL || *stack == NULL)
		outerr(7, line_numbea);

	Ptr = *stack;
	*stack = Ptr->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(Ptr);
}
