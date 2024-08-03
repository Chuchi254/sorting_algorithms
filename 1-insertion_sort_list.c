#include "sort.h"

/**
 * swaap_nodes - Swaps two nodes in a doubly linked list
 * @list: Pointer to the head of the doubly linked list
 * @left: Pointer ot the left node to be swapped
 * @right; Pointer to the right node to be swapped
 */
void swap_nodes(listint_t **list, listint_t *left, listint_t *right)
{
	if (left->prev)
		left->prev->next = right;
	if (right->next)
		right->next->prev = left;
	left->next = right->next;
	right->prev = left->prev;
	right->next = left;
	left->prev = right;

	if (right->prev == NULL)
		*list = right;
}

/**
 * insert_sort_list - Sorts a doubly linked list of integers in ascending
 * order using the Insertion sort
 * @list: Pointer to the ehad of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *key;

	if (!list || !*list || !(*list)->next)
		return;

	current = (*list)->next;

	while (current)
	{
		key = current;
		current = current->next;

		while (key->prev && key->prev->n > key->n)
		{
			swap_nodes(list, key->prev, key);
			print_list(*list);
		}
	}
}
