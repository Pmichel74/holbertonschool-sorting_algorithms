#include "sort.h"

/**
 * bubble_sort - sort an array of integers
 * @array: integer array
 * @size: array size
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, len = size;
	int tmp, swap;

	if (array == NULL || size < 2)
		return;

	while (len)
	{
		swap = 0;/*reinitialisé a 0 chaque passage*/
		for (i = 0; i < len - 1; i++)/*-1 evite de dépasser limite du tableau*/
		{
			if (array[i] > array[i + 1])/* si élément actuel > que le suivant*/
			{
				tmp = array[i + 1];
				/*Déplace l'élément de gauche (i) vers la droite*/
				array[i + 1] = array[i];
				/*Place la valeur temporaire à la position de gauche*/
				array[i] = tmp;
				print_array(array, size);
				swap = 1;/*indique qu'il ya eu echange*/
			}
		}
		len--;
		if (swap == 0)
			break;
	}
}
