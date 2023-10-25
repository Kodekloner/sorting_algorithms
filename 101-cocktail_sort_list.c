#include "sort.h"

/**
 * swap_nd_ahead - Swap a node in a listint_t doubly-linked list
 *                   list of integers with the node ahead of it.
 * @lst: A pointer to the head of a doubly-linked list of integers.
 * @bottom: A pointer to the tail of the doubly-linked list.
 * @mixer: A pointer to the current swapping node of the cocktail mixer algo.
 */
void swap_nd_ahead(listint_t **lst, listint_t **bottom, listint_t **mixer)
{
	listint_t *temp = (*mixer)->next;

	if ((*mixer)->prev != NULL)
		(*mixer)->prev->next = temp;
	else
		*lst = temp;
	temp->prev = (*mixer)->prev;
	(*mixer)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = *mixer;
	else
		*bottom = *mixer;
	(*mixer)->prev = temp;
	temp->next = *mixer;
	*mixer = temp;
}

/**
 * swap_node_behind - Swap a node in a listint_t doubly-linked
 *                    list of integers with the node behind it.
 * @lst: A pointer to the head of a doubly-linked list of integers.
 * @bottom: A pointer to the tail of the doubly-linked list.
 * @mixer: A pointer to the current swapping node of the cocktail mixer algo.
 */
void swap_nd_behind(listint_t **lst, listint_t **bottom, listint_t **mixer)
{
	listint_t *temp = (*mixer)->prev;

	if ((*mixer)->next != NULL)
		(*mixer)->next->prev = temp;
	else
		*bottom = temp;
	temp->next = (*mixer)->next;
	(*mixer)->prev = temp->prev;
	if (temp->prev != NULL)
		temp->prev->next = *mixer;
	else
		*lst = *mixer;
	(*mixer)->next = temp;
	temp->prev = *mixer;
	*mixer = temp;
}

/**
 * cocktail_sort_list - Sort a listint_t doubly-linked list of integers in
 *                      ascending order using the cocktail mixer algorithm.
 * @list: A pointer to the head of a listint_t doubly-linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *bottom, *mixer;
	bool shaken_not_mixed = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (bottom = *list; bottom->next != NULL;)
		bottom = bottom->next;

	while (shaken_not_mixed == false)
	{
		shaken_not_mixed = true;
		for (mixer = *list; mixer != bottom; mixer = mixer->next)
		{
			if (mixer->n > mixer->next->n)
			{
				swap_nd_ahead(list, &bottom, &mixer);
				print_list((const listint_t *)*list);
				shaken_not_mixed = false;
			}
		}
		for (mixer = mixer->prev; mixer != *list;
				mixer = mixer->prev)
		{
			if (mixer->n < mixer->prev->n)
			{
				swap_nd_behind(list, &bottom, &mixer);
				print_list((const listint_t *)*list);
				shaken_not_mixed = false;
			}
		}
	}
}
