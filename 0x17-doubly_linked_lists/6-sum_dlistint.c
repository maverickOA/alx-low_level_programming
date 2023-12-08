#include "lists.h"

/**
 * sum_dlistint - Add all the values in a doubly
 * linked list.
 *
 * @head: The memory address to the head node in the
 * list.
 *
 * Return: The sum of all the values in the list
 * elements.
 *
 **/
int sum_dlistint(dlistint_t *head)
{
	dlistint_t *current = NULL;
	int sum = 0;

	current = head;
	while (current != NULL)
	{
		sum += current->n;
		current = current->next;
	}

	return (sum);
}
