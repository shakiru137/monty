#include "monty.h"
/**
 * print_top -  to prints the top
 * @head: the stack head
 * @counter: the line number
 * Return: nothing
*/
void print_top(stack_t **head, unsigned int counter)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't print, stack empty\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*head)->n);
}
