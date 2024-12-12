#include "sort.h"

/**
 * insertion_sort_list - sorts a linked list using insertion sort
 *
 * @list: the address of a pointer to the head of a list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *n1, *n2;

	if (list == NULL || *list == NULL)
		return;

	n1 = (*list)->next;

	while (n1)
	{
		n2 = n1->next;/* boucle commence au 2eme élément*/
		/* check si noeud actuel est le 1e de la liste*/
		/* la valeur du noeud precedent > a celle du noeud actuel*/
		while (n1->prev != NULL && n1->prev->n > n1->n)
		n1->prev->next = n1->next;/*A <-> n1 <-> B*/ /*après: A-->B(n1)*/

				if (n1->next)
				n1->next->prev = n1->prev;

			n1->next = n1->prev;/*next de n1 vers son noeud précédent*/
			n1->prev = n1->next->prev;/*place n1 avant son ancien précédent*/
			n1->next->prev = n1;/*complète l'insertion de n1 à sa nouvelle position.*/

			if (!n1->prev)/*verifie si n1 est devenu 1er élément*/
				*list = n1;/*maj pointeur de tete pour pointer vers n1*/
			else
				n1->prev->next = n1;/*si n1 pas 1er élément*/
			print_list(*list);/*affiche liste après chaque insertion*/
		}
		n1 = n2;/*fait avancer n1 au prochain noeud*/
	}

