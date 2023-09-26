#include "sort.h"

/**
 * insertion_sort_list - sorts a double linked list in an ascending order
 * @list: double pointer to the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *prev, *current, *tmp;

	if (list == NULL || *list == NULL)
		exit(1);
	current = (*list)->next;
	while (current != NULL)
	{
		tmp = current;
		prev = current->prev;
		while (prev != NULL && tmp->prev->n > tmp->n)
		{
			tmp->prev->next = tmp->next;
			if (tmp->next != NULL)
				tmp->next->prev = tmp->prev;
			tmp->next = prev;
			tmp->prev = prev->prev;
			prev->prev = tmp;
			if (tmp->prev != NULL)
				tmp->prev->next = tmp;
			else
				*list = tmp;
			print_list(*list);
			prev = tmp->prev;
		}
		current = current->next;
	}
}
