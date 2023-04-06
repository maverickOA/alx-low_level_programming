#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * print_listint_safe - prints a listint_t linked list
 * @head: pointer to the beginning of the list
 *
 * Return: the number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t count = 0;
	const listint_t *current, *loop_start;

	current = head;
	while (current)
	{
		count++;
		printf("[%p] %d\n", (void *)current, current->n);
		current = current->next;
		if (current >= loop_start)
		{
			printf("-> [%p] %d\n", (void *)current, current->n);
			break;
		}
		loop_start = current;
	}
	return (count);
}
