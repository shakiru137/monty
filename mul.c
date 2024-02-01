#include "monty.h"
/**
 * mul_F -  to multipy the top two elements of the stack together.
 * @head: the stack head
 * @counter: line number
 * Return: nothing
*/
void mul_F(stack_t **head, unsigned int counter)
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
		fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	h = *head;
	i = h->next->n * h->n;
	h->next->n = i;
	*head = h->next;
	free(h);
}
