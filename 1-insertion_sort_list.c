#include "sort.h"

/**
 * insertion_sort_list - sort function
 * @list: our doubly linked list
 *
 * Return: no return
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *sorted = NULL;
	listint_t *current = *list;
	listint_t *next;
	listint_t *current_sorted;

	while (current != NULL)
	{
		next = current->next;
		if (sorted == NULL || sorted->n >= current->n)
		{
			current->next = sorted;
			if (sorted != NULL)
			{
				sorted->prev = current;
			}
			current->prev = NULL;
			sorted = current;
		}
		else
		{
			current_sorted = sorted;
			while (current_sorted->next != NULL && current_sorted->next->n < current->n)
			{
				current_sorted = current_sorted->next;
			}
			current->next = current_sorted->next;
			if (current_sorted->next != NULL)
			{
				current_sorted->next->prev = current;
			}
			current->prev = current_sorted;
			current_sorted->next = current;
		}
		current = next;
		*list = sorted;
	}
}
