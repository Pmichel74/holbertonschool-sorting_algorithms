#include "sort.h"

/**
 * insertion_sort_list - sorts a linked list using insertion sort
 *@list: the address of a pointer to the head of a list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *swap_node, *next_swap;

	if (list == NULL || *list == NULL)
		return;

	swap_node = (*list)->next;

	while (swap_node)
	{
		next_swap = swap_node->next;/* boucle commence au 2eme élément*/
		/* check si noeud actuel est le 1e de la liste*/
		/* la valeur du noeud precedent > a celle du noeud actuel*/
		while (swap_node->prev != NULL && swap_node->prev->n > swap_node->n)
		/*A <-> swap_node <-> B*/ /*après: A-->B(swap_node)*/
		swap_node->prev->next = swap_node->next;

				if (swap_node->next)
				swap_node->next->prev = swap_node->prev;

			swap_node->next = swap_node->prev;
			/*next de swap_node vers son noeud précédent*/
			swap_node->prev = swap_node->next->prev;
			/*place swap_node avant son ancien précédent*/
			swap_node->next->prev = swap_node;
			/*complète l'insertion de swap_node à sa nouvelle position.*/

			if (!swap_node->prev)/*verifie si swap_node est devenu 1er élément*/
				*list = swap_node;/*maj pointeur de tete pour pointer vers swap_node*/
			else
				swap_node->prev->next = swap_node;/*si swap_node pas 1er élément*/
			print_list(*list);/*affiche liste après chaque insertion*/
		}
		swap_node = next_swap;/*fait avancer swap_node au prochain noeud*/
	}
