#include "sort.h"



listint_t *getLinkNode(const int n)
{
	listint_t *list = (listint_t *) malloc(sizeof(listint_t));
	if (list == NULL)
	{
		return (NULL);
	}
	list->n = n;
	list->next = NULL;
	list->prev = NULL;
	return (list);
}

typedef struct DoubleLinkedList
{
	struct listint_s *head;
	struct listint_s *tail;	
}DoubleLinkedList;

DoubleLinkedList *getDoubleLinkedList()
{
	DoubleLinkedList *list = (DoubleLinkedList * ) malloc(sizeof(DoubleLinkedList));
	if (list == NULL)
	{
		return (NULL);
	}
	list->head = NULL;
	list->tail = NULL;
	return (list);
}

void insert(DoubleLinkedList *list, int value)
{
	listint_t *node = getLinkNode(value);
	if ((list->head = NULL))
	{
		list->head = node;
		list->tail = node;
		return;
	}
	list->tail->next = node;
	node->prev = list->tail;
	list->tail = node;
}

void swapData(listint_t *first, listint_t *second)
{
	int value = first->n;
	first->n = second->n;
	second->n = value;
}

/**
 * selection_sort - sort using insertion sort
 * @list: double linked list to be sorted
 * 
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *front = *list;
	listint_t *back = NULL;

	while (front != NULL)
	{
		back = front->next;

		while (back != NULL &&
				back->prev != NULL &&
				back->n < back->prev->n)
		{
			swapData(back, back->prev);
			back = back->prev;			
		}
		front = front->next;		
	}
	
}