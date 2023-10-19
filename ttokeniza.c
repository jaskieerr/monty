#include "monty.h"

/**
 * tokenizea - toknizezes
 * @buffea: the line to be tokenized
 * @line_num: line nubea
 * @format: checks if a or stack
 * Return: Returns 0 if stack, 1 if queue.
 */
int tokenizea(char *buffea, int line_num, int format)
{
	char *opcode, *val;
	const char *delimiter = "\n ";

	if (buffea == NULL)
		out_error(4);

	opcode = strtok(buffea, delimiter);
	if (opcode == NULL)
		return (format);
	val = strtok(NULL, delimiter);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	findd(opcode, val, line_num, format);
	return (format);
}
/**
 * enqueue - adds node to q
 * @q: new node location
 * @linu: line location
 */
void enqueue(stack_t **q, __attribute__((unused))unsigned int linu)
{
	stack_t *tempo;

	if (q == NULL || *q == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *q;
		return;
	}
	tempo = head;
	while (tempo->next != NULL)
		tempo = tempo->next;

	tempo->next = *q;
	(*q)->prev = tempo;
}
