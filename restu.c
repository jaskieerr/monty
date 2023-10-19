#include"monty.h"

/**
 * pint - priints the top elm of stack
 * @stack: double pointer to last stack node
 * @line_numbea: line number of opcode
 */
void pint(stack_t **stack, unsigned int line_numbea)
{
	if (stack == NULL || *stack == NULL)
		outerr(6, line_numbea);
	printf("%d\n", (*stack)->n);
}

/**
 * outerr- it outs the errors
 * @anerroru: just some error codes ukwharamsayin
 */
void outerr(int anerroru, ...)
{
	va_list argg;
	char *op;
	int numb_ln;

	va_start(argg, anerroru);
	switch (anerroru)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(argg, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(argg, int));
			break;
		case 8:
			numb_ln = va_arg(argg, unsigned int);
			op = va_arg(argg, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", numb_ln, op);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(argg, unsigned int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}
