#include "lists.h"

/**
 * print_dlistint - Print all the elements in the given
 * list.
 *
 * @h: The memory address to the head node in the list.
 *
 * Return: The number of nodes available in the list
 *
 **/
size_t print_dlistint(const dlistint_t *h)
{
	size_t number_of_nodes = 0;
	const dlistint_t *current = NULL;

	current = h;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
		number_of_nodes++;
	}

	return (number_of_nodes);
}
