#include "lists.h"
#include <stdlib.h>

/**
 * listint_t *add_nodeint - function that adds a new node at the
 * beginning of a listint_t list.
 *
 * @head: a pointer which points to another pointer,the head
 * @n: Parameter with the value of the number data
 *
 * Return: the address of the new element, or NULL if it failed
 */

listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
	{
		return (NULL);
	}
	new->n = n;
	new->next = *head;
	*head = new;

	return (new);
}
