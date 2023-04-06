#include <stdlib.h>

typedef struct listint_s
{
	int n;
	struct listint_s *next;
} listint_t;

size_t free_listint_safe(listint_t **h)
{
	size_t size = 0;
	listint_t *current, *next;

	if (h == NULL || *h == NULL)
	return (0);

	current = *h;
	*h = NULL;

	while (current != NULL)
	{
	size++;
	next = current->next;
	free(current);
	if (next >= current)
	break;
	current = next;
	}

	return (size);
}
