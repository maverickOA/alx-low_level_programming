#include "lists.h"

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new_node, *temp = *head;

	if (!head)
	return NULL;
	if (!idx)
	return add_nodeint(head, n);

	for (; temp && --idx; temp = temp->next);

	if (!temp)
	return NULL;

	new_node = malloc(sizeof(listint_t));
	if (!new_node)
	return NULL;

	new_node->n = n;
	new_node->next = temp->next;
	temp->next = new_node;

	return new_node;
}
