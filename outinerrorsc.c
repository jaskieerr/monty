#include "monty.h"


/**
 * out_error - outs errors
 * @erroru: the error codes to be outed
 */
void out_error(int erroru, ...)
{
	va_list arguments;
	char *opcodes;
	int line_numbea;

	va_start(arguments, erroru);
	switch (erroru)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't opcodesen file %s\n",
				va_arg(arguments, char *));
			break;
		case 3:
			line_numbea = va_arg(arguments, int);
			opcodes = va_arg(arguments, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", line_numbea, opcodes);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usargumentse: push integer\n", va_arg(arguments, int));
			break;
		default:
			break;
	}
	dealloc();
	exit(EXIT_FAILURE);
}
