#include "sort.h"

/**
 * swapping_ndes - Swapping two nodes in a listint_t doubly-linked list.
 * @head: Pointer to the head of the doubly-linked list.
 * @node1: Pointer to the first node to be swapped.
 * @node2: Pointer to the Second node to be swapped.
 */
void swapping_ndes(listint_t **head, listint_t **node1, listint_t *node2)
{
	(*node1)->next = node2->next;
	if (node2->next != NULL)
		node2->next->prev = *node1;
	node2->prev = (*node1)->prev;
	node2->next = *node1;
	if ((*node1)->prev != NULL)
		(*node1)->prev->next = node2;
	else
		*head = node2;
	(*node1)->prev = node2;
	*node1 = node2->prev;
}

/**
 * insertion_sort_list - Using the insertion sort algorithm to
 *												Sorts a doubly linked list of integers.
 * @list: Pointer to the head of a doubly-linked list of integers.
 *
 * Description: After each swap, the lists is printed.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *ite, *ins, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (ite = (*list)->next; ite != NULL; ite = temp)
	{
		temp = ite->next;
		ins = ite->prev;
		while (ins != NULL && ite->n < ins->n)
		{
			swapping_ndes(list, &ins, ite);
			print_list((const listint_t *)*list);
		}
	}
}
