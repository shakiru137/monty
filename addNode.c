#include "monty.h"
/**
 * addNode - add node to the head stack
 * @head: head of the stack
 * @n: new value
 * Return: Nothing
*/
void addNode(stack_t **head, int n)
{
	stack_t *newNode;
	stack_t *temp;

	temp = *head;
	newNode = malloc(sizeof(stack_t));
	if (newNode == NULL)
	{
		printf("Error\n");
		exit(0);
	}
	if (temp)
		temp->prev = newNode;
	newNode->n = n;
	newNode->next = *head;
	newNode->prev = NULL;
	*head = newNode;
}
