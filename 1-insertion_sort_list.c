#include "sort.h"
/**
* insertion_sort_list - sorts a double linked list using insertion sort
* @list: points to the double linked list head pointer
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *head = *list, *h, *temp, *h_prev, *tp;

	if (list == NULL || (*list) == NULL || (*list)->next == NULL)
		return;
	while (head)
	{
		h = head;
		while (h->prev)
		{
			h_prev = h->prev;
			if (h_prev->n > h->n)
			{
				tp = h_prev->prev;
				temp = h->next;
				h->prev = tp;
				h->next = h_prev;
				h_prev->next = temp;
				h_prev->prev = h;
				if (temp)
					temp->prev = h_prev;
				if (tp)
					tp->next = h;
				else
					*list = h;
				print_list(*list);
			}
			else
				break;
		}
		head = head->next;
	}
}
