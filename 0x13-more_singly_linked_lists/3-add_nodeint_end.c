#include "lists.h"
#include <stdlib.h>

/**
  * listint_t *add_nodeint_end - function that  add node at
  * end of a listint_t list.
  *
  * @head: pointer to that points to another pointer, the head
  *  @n: value of new number data
  * Return: the address of the new element, or NULL if it failed
  */

listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new, *temp;
		if (head == NULL)
		return (NULL);
	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	new->next = NULL;
	if (*head == NULL)
	{
	*head = new;
		return (new);
	}
	temp = *head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = new;
	return (new);
}
