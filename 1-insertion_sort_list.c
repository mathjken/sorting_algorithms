#include "sort.h"

/**
 * insertion_sort_list - inserts right unsorted side into left sorted side
 * @list: doubly linked list to sort
 *
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *new_n, *old, *nextnode;

	if (list == NULL || !(*list) || (*list)->next == NULL)
		return;
	new_n = (*list)->next;
	nextnode = new_n->next;
	while (new_n)
	{
		if (new_n->n < new_n->prev->n)
		{
			old = new_n->prev;
			while (old && (new_n->n < old->n))
			{
				if (!(old->prev))
				{
					old->prev = new_n;
					new_n->prev->next = new_n->next;
					if (new_n->next)
						new_n->next->prev = new_n->prev;
					new_n->next = old;
					new_n->prev = NULL;
					*list = new_n;
				}
				else
				{
					new_n->prev->next = new_n->next;
					if (new_n->next)
						new_n->next->prev = new_n->prev;
					old->prev->next = new_n;
					new_n->prev = old->prev;
					old->prev = new_n;
					new_n->next = old;
				}
				print_list(*list);
				old = new_n->prev;
			}
		}
		new_n = nextnode;
		new_n ? (nextnode = new_n->next) : (nextnode = NULL);
	}
}
