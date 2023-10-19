#include "monty.h"


/**
 * out_error - outs errors
 * @erroru: the error codes to be outed
 */
void out_error(int erroru, ...)
{
	va_list argus;
	char *opcodes;
	int line_numbea;

	va_start(argus, erroru);
	switch (erroru)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't opcodesen file %s\n",
				va_arg(argus, char *));
			break;
		case 3:
			line_numbea = va_arg(argus, int);
			opcodes = va_arg(argus, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", line_numbea, opcodes);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(argus, int));
			break;
		default:
			break;
	}
	dealloc();
	exit(EXIT_FAILURE);
}
