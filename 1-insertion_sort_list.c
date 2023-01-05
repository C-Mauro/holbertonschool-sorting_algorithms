#include "sort.h"

/**
 * insertion_sort_list - sorts a dobuly linked list as per the insertion method
 *
 * @list: head of the d-linked list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *store, *previous, *swappable;

	if (!list || !*list || !(*list)->next)
		return;

	store = *list;

	while ((store = store->next))
	{
		swappable = store;

		while (swappable->prev && swappable->n < swappable->prev->n)
		{
			previous = swappable->prev;

			if (swappable->next)
				swappable->next->prev = previous;

			if (previous->prev)
				previous->prev->next = swappable;

			else
				*list = swappable;

			previous->next = swappable->next;
			swappable->prev = previous->prev;
			swappable->next = previous;
			previous->prev = swappable;

			print_list(*list);
		}
	}
}
