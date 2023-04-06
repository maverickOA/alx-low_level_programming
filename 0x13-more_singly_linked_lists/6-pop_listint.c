#include <stdlib.h>
#include "lists.h"

/**
 * pop_listint - Deletes the head node of a listint_t linked list
 *               and returns the head node's data.
 * @head: A pointer to a pointer to the head of the linked list.
 *
 * Return: The head node's data, or 0 if the list is empty.
 */
int pop_listint(listint_t **head)
{
	listint_t *current;
	int n;

	if (head == NULL || *head == NULL)
	return 0;

	current = *head;
	*head = (*head)->next;
	n = current->n;
	free(current);

	return n;
}
