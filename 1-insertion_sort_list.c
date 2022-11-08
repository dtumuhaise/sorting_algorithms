#include "sort.h"
/**
 * insertion_sort_list - sorts doubly linked list
 * @list: list to be sorted
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *front, *back, *nextnode;

	if (list == NULL || !(*list) || (*list)->next == NULL)
		return;
	front = (*list)->next;
	nextnode = front->next;
	while (front)
	{
		if (front->n < front->prev->n)
		{
			back = front->prev;
			while (back && (front->n < back->n))
			{
				if (!(back->prev))
				{
					back->prev = front;
					front->prev->next = front->next;
					if (front->next)
						front->next->prev = front->prev;
					front->next = back;
					front->prev = NULL;
					*list = front;
				}
				else
				{
					front->prev->next = front->next;
					if (front->next)
						front->next->prev = front->prev;
					back->prev->next = front;
					front->prev = back->prev;
					back->prev = front;
					front->next = back;
				}
				print_list(*list);
				back = front->prev;
			}
		}
		front = nextnode;
		front ? (nextnode = front->next) : (nextnode = NULL);
	}
}
