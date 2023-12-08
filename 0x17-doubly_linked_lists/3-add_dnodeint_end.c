#include "lists.h"

/**
 * add_dnodeint_end - Add a new node at the end of the
 * given list.
 *
 * @head: The memory address to the head  node in the
 * list.
 * @n: The value for the newly added node
 *
 * Return: The memory address of the newly added node.
 *
 **/
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *node = NULL, *current = NULL;

	node = malloc(sizeof(dlistint_t));
	if (node == NULL)
	{
		printf("Can't malloc\n");
		return (NULL);
	}
	node->n = n;
	node->next = NULL;
	node->prev = NULL;
	if ((*head) == NULL)
	{
		(*head) = node;
		return (*head);
	}
	current = (*head);
	while (current->next != NULL)
	{
		current = current->next;
	}
	node->prev = current;
	current->next = node;

	return (node);
}
