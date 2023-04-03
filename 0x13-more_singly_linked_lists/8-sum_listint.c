#include "lists.h"
#include <stdlib.h>

/**
 * sum_listint - a function that calculates the sum of all the
 * data in a listint_t list
 * @head: pointer to the node
 *
 * Return: sum of all the data(n) of a listint_t linked list
 */
int sum_listint(listint_t *head)
{
	int sum = 0;

	while (head != NULL)
	{
		sum += head->n;
		head = head->next;
	}
	return (sum);
}
