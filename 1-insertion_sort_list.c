#include "sort.h"



/**
 * insertion_sort_list - sorting a doubly linked list using insertion sort
 * algorithm
 * @list: Pointer to the head of the doubly linked list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *ptr, *present_ptr, *previous_ptr;

	if (!list)
		return;
	present_ptr = NULL;
	previous_ptr = NULL;
	ptr = *list;

	while (ptr)
	{
		present_ptr = ptr;
		previous_ptr = ptr->prev;
		while (previous_ptr)
		{
			if (present_ptr->n < previous_ptr->n)
			{
				previous_ptr->next = present_ptr->next;
				if (present_ptr->next)
					(present_ptr->next)->prev = previous_ptr;
				present_ptr->prev = previous_ptr->prev;
				if (previous_ptr->prev)
					(previous_ptr->prev)->next = present_ptr;
				else
					*list = present_ptr;
				previous_ptr->prev = present_ptr;
				present_ptr->next = previous_ptr;
				previous_ptr = present_ptr;
				print_list(*list);
			}
			present_ptr = previous_ptr;
			previous_ptr = previous_ptr->prev;
		}
		*list = present_ptr;
		ptr = ptr->next;
	}
}
