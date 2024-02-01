#include "monty.h"
/**
 * add_F - add the top two elements of the stack together.
 * @head: the stack head
 * @counter: line_number
 * Return: Nothing
*/
void add_F(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int len = 0, i;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}

	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	h = *head;
	i = h->n + h->next->n;
	h->next->n = i;
	*head = h->next;
	free(h);
}
