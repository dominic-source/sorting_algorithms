#include "sort.h"

/**
 * list_length - function to compute list length
 * @list: head of list
 *
 * Return: list length
 */
size_t list_length(listint_t *list)
{
	size_t len = 0;

	while (list)
	{
		len++;
		list = list->next;
	}
	return (len);
}

/**
 * switch_node - function swaps two nodes
 * @list: head of list
 * @p: pointer to node
 */
void switch_node(listint_t **list, listint_t **p)
{
	listint_t *n1, *n2, *n3, *n4;

	n1 = (*p)->prev;
	n2 = *p;
	n3 = (*p)->next;
	n4 = (*p)->next->next;
	n2->next = n4;
	if (n4)
		n4->prev = n2;
	n3->next = n2;
	n3->prev = n2->prev;
	if (n1)
		n1->next = n3;
	else
		*list = n3;
	n2->prev = n3;
	*p = n3;
}


/**
 * cocktail_sort_list - sorts a doubly linked list using Cocktail shaker sort
 *
 * @list: pointer to the head of a doubly linked list
*/
void cocktail_sort_list(listint_t **list)
{
	listint_t *i;
	int sorted = 0;

	if (!list || !*list || list_length(*list) < 2)
		return;
	i = *list;
	while (!sorted)
	{
		sorted = 1;
		while (i->next)
		{
			if (i->n > i->next->n)
			{
				sorted = 0;
				switch_node(list, &i);
				print_list(*list);
			}
			else
				i = i->next;
		}
		if (sorted)
			break;
		i = i->prev;
		while (i->prev)
		{
			if (i->n < i->prev->n)
			{
				sorted = 0;
				i = i->prev;
				switch_node(list, &i);
				print_list(*list);
			}
			else
				i = i->prev;
		}
	}
}

