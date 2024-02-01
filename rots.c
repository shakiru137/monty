#include "monty.h"
/**
  *rotate- rotates the stack to the top
  *@head: stack head
  *@counter: line_number
  *Return: no return
 */
void rotate(stack_t **head,  __attribute__((unused)) unsigned int counter)
{
	stack_t *tmp = *head, *tp;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}

	tp = (*head)->next;
	tp->prev = NULL;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}

	tmp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = tmp;
	(*head) = tp;
}
