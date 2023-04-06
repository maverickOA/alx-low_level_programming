#include "lists.h"

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *temp, *prev;
	unsigned int i;

	if (!head || !*head)
	return -1;

	temp = *head;
	prev = NULL;

	for (i = 0; i < index && temp; i++)
	{
	prev = temp;
	temp = temp->next;
	}

	if (!temp)
	return -1;

	if (!prev)
	*head = temp->next;
	else
	prev->next = temp->next;

	free(temp);

	return 1;
}
