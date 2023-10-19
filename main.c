#include "monty.h"
stack_t *head = NULL;

/**
 * main - Entry point
 * @argc: arg count
 * @argv: arg vector
 * Return: Nada
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file_oppen(argv[1]);
	dealloc();
	return (0);
}
