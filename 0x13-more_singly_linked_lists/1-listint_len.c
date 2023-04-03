#include "lists.h"

/**
 * listint_len - a function returns number of elements in a linked listint_t.
 *
 * @h: Parameter that Points to the head of the linked list
 *
 * Return: the number of elements in listint_t list.
 */

size_t listint_len(const listint_t *h)
{
	size_t n = 0;

	while (h != NULL)
	{
		h = h->next;
		n++;
	}

	return (n);
}
