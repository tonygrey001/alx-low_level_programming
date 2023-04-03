#include "lists.h"
#include <stdlib.h>

/**
 * listint_t *get_nodeint_at_index - function that returns the nth node of a
 * listint_t linked list.
 *
 * @head: a pointer that points to the head of the linked list
 * @index: index of the node, starting at 0
 *
 * Return: the node position
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	listint_t *new = head;
	unsigned int i;

	if (head == NULL)
		return (NULL);
	for (i = 0; i < index && new; i++)
	{
		if (new->next == NULL)
			return (NULL);
		new = new->next;
	}
	return (new);
}
