#include <stddef.h>
#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked
 * list using insertion sort
 *
 * @list: pointer to pointer to list to be sorted
 *
 * Return: void
 *
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *previous, *head;

	if (list == NULL)
		return;
	head = *list;

	while (head != NULL)
	{
		current = head;
		previous = head->prev;
		while (previous && current)
		{
			if (previous->n > current->n)
			{
				previous->next = current->next;
				if (current->next)
				{
					current->next->prev = previous;
				}
				current->next = previous;
				current->prev = previous->prev;
				if (previous->prev)
				{
					previous->prev->next = current;
				}
				previous->prev = current;
				if (current == head)
				{
					head = previous;
				}
				previous = current->prev;
			}
			else
				break;
			if (previous == NULL)
				*list = current;
			print_list(*list);
		}
		head = head->next;
	}
}

