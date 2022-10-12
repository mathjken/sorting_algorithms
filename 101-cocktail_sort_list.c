#include "sort.h"
/**
 * swap - swaps both
 * @first: first node to swap
 * @second: second node to swap
 * @list: list to set null or not
 */
void swap(listint_t *first, listint_t *second, listint_t **list)
{
	if (!(first->prev))
	{
		first->next = second->next;
		if (second->next)
			second->next->prev = first;
		second->next = first;
		second->prev = NULL;
		first->prev = second;
		*list = second;
	}
	else
	{
		second->prev->next = second->next;
		if (second->next)
			second->next->prev = second->prev;
		first->prev->next = second;
		second->prev = first->prev;
		first->prev = second;
		second->next = first;
	}
}

/**
 * cocktail_sort_list - inserts right unsorted side into left sorted side
 * @list: doubly linked list to sort
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *node, *nextnode;
	int checker;

	if (list == NULL || !(*list) || (*list)->next == NULL)
		return;

	node = (*list);
	do {
		checker = 0;
		while (node->next)
		{
			nextnode = node->next;
			if (nextnode && node->n > nextnode->n)
			{
				swap(node, nextnode, list);
				checker = 1;
				print_list((*list));
			}
			else
				node = node->next;
		}
		node = node->prev;
		while (node->prev)
		{
			nextnode = node->prev;
			if (nextnode && node->n < nextnode->n)
			{
				swap(nextnode, node, list);
				checker = 1;
				print_list((*list));
			}
			else
				node = node->prev;
		}
		node = node->next;
	} while (checker);
}
