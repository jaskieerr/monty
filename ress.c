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

/**
 * add - adds the top two elements of the stack
 * @stack: double ptr to  top of stack
 * @line_numbea: line numbea goddamit
 */
void add(stack_t **stack, unsigned int line_numbea)
{
	int resultu;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		outerr(8, line_numbea, "add");

	(*stack) = (*stack)->next;
	resultu = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = resultu;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
/**
 * swap - swaps 2 top elements of stack
 * @stack: double pointer to top of stack
 * @line_numbea: Iif i had a penny everytime i ...
 */
void swap(stack_t **stack, unsigned int line_numbea)
{
	stack_t *Ptr;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		outerr(8, line_numbea, "swap");
	Ptr = (*stack)->next;
	(*stack)->next = Ptr->next;
	if (Ptr->next != NULL)
		Ptr->next->prev = *stack;
	Ptr->next = *stack;
	(*stack)->prev = Ptr;
	Ptr->prev = NULL;
	*stack = Ptr;
}
