#include "lists.h"

/**
 * delete_dnodeint_at_index - Remove the node at the
 * given index from a doubly linked list.
 *
 * @head: The memory address to the head node in the
 * list.
 * @index: The index of the node to be removed
 *
 * Return: 1 if the remove operation succeeds otherwise
 * 0
 *
 **/
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current = NULL, *previous = NULL, *node = NULL;
	unsigned int node_count = 0;

	current = (*head);
	while (current != NULL)
	{
		node = current;
		if (node_count == index)
		{
			node = current->next;
			if (node != NULL)
			{
				node->prev = previous;
			}
			if (previous != NULL)
			{
				previous->next = node;
			}
			if (index == 0)
			{
				(*head) = node;
			}
			free(current);
			return (1);
		}
		previous = current;
		current = current->next;
		node_count++;
	}
	return (-1);
}
