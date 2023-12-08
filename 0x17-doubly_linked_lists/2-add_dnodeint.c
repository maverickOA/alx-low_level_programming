#include "lists.h"

/**
 * add_dnodeint - Add a new node at the beginning of
 * the given list.
 *
 * @head: The memory address to the head node in the
 * list.
 * @n: The value for the newly added node.
 *
 * Return: The memory address of the newly added node.
 *
 **/
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *node = NULL;

	node = malloc(sizeof(dlistint_t));
	if (node == NULL)
	{
		printf("Error: Can't malloc\n");
		return (NULL);
	}
	node->n = n;
	node->next = (*head);
	node->prev = NULL;
	if ((*head) != NULL)
	{
		(*head)->prev = node;
	}
	(*head) = node;

	return (*head);
}
