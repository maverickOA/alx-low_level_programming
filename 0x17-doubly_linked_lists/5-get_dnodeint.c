#include "lists.h"

/**
 * get_dnodeint_at_index - Locate the node at the given
 * index @index.
 *
 * @head: The memory address to the head node in the
 * list
 * @index: The index for the node to be located in
 * the list.
 *
 * Return: The node located at @index.
 *
 **/
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	dlistint_t *current = NULL;
	unsigned int node_count = 0;

	current = head;
	while (current != NULL)
	{
		if (node_count == index)
		{
			return (current);
		}
		current = current->next;
		node_count++;
	}

	return (NULL);
}
