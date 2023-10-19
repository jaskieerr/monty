#include "monty.h"

/**
 * readd - reads a file
 * @fptr: file pointer
 * Return: Nada
 */

void readd(FILE *fptr)
{
	int line, format = 0;
	char *buffea = NULL;
	size_t len = 0;

	for (line = 1; getline(&buffea, &len, fptr) != -1; line++)
	{
		format = tokenizea(buffea, line, format);
	}
	free(buffea);
}

/**
 * file_oppen - oppens the file
 * @file: file tobe oopend
 * Return: Nada
 */

void file_oppen(char *file)
{
	FILE *fptr = fopen(file, "r");

	if (file == NULL || fptr == NULL)
		out_error(2, file);

	readd(fptr);
	fclose(fptr);
}

/**
 * dealloc - deallocates node memory
 */
void dealloc(void)
{
	stack_t *tmp;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

/**
 * makenode - makes a node
 * @n: int to be inseterd
 * Return:node ptr or null if failure
 */
stack_t *makenode(int n)
{
	stack_t *anode;

	anode = malloc(sizeof(stack_t));
	if (anode == NULL)
		out_error(4);
	anode->next = NULL;
	anode->prev = NULL;
	anode->n = n;
	return (anode);
}
