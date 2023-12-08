#include "lists.h"

/**
 * free_dlistint - Free the memory allocated to a doubly
 * linked list.
 *
 * @head: The memory address to the head node in the
 * list to be freed.
 *
 **/
void free_dlistint(dlistint_t *head)
{
	dlistint_t *current = NULL;

	if (head == NULL)
	{
		return;
	}
	current = head;
	while (current->next != NULL)
	{
		free(current->prev);
		current = current->next;
	}
	free(current->prev);
	free(current);
}
