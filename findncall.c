#include "monty.h"

/**
 * findd - fin function for the opcode
 * @opcode: the opcode
 * @val: opcode arg
 * @sorq: if 0 stack
 * @line_num: if 1 its a q
 * Return: Nada
 */
void findd(char *opcode, char *val, int line_num, int sorq)
{
	int i;
	int checkk;

	instruction_t funcstionss[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"nop", nop},
		{"pop", pop},
		{"add", add},

		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (checkk = 1, i = 0; funcstionss[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, funcstionss[i].opcode) == 0)
		{
			call_fun(funcstionss[i].f, opcode, val, line_num, sorq);
			checkk = 0;
		}
	}
	if (checkk == 1)
		out_error(3, line_num, opcode);
}

/**
 * call_fun - calls the function
 * @fun: fucntion pointer
 * @op: opcode as string
 * @val: opcode string numbea
 * @ln: instruction lines
 * @sorq: checks if stack or q
 */
void call_fun(op_func fun, char *op, char *val, int ln, int sorq)
{
	stack_t *node;
	int checkk;
	int i;

	checkk = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			checkk = -1;
		}
		if (val == NULL)
			out_error(5, ln);
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				out_error(5, ln);
		}
		node = makenode(atoi(val) * checkk);
		if (sorq == 0)
			fun(&node, ln);
		if (sorq == 1)
			enqueue(&node, ln);
	}
	else
		fun(&head, ln);
}
