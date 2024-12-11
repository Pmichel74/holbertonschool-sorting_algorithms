#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * bubble_sort - Sort an array of integers in ascending order.
 * @array: Array of integers to sort.
 * @size: The size of the array.
 *
 * Description: Prints the array after each time you swap.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, len = size;
	bool bubbly = false;

	if (array == NULL || size < 2)
		return;

	while (bubbly == false)/*false: continue tant qu'il y a des échanges*/
	{
		bubbly = true;/*si pas d'échange bubbly restera a true et fin de boucle*/
		for (i = 0; i < len - 1; i++) /*-1 evite de dépasser limite du tableau*/
		{
			if (array[i] > array[i + 1]) /* si élément actuel > que le suivant*/
			{
				swap_ints(array + i, array + i + 1);
				/*fonction swap_ints pour swapper 2 élements*/
				/*+ i 1er élément a échanger-->> + i + 1 élément suivant*/
				print_array(array, size);
				bubbly = false;
				/* false: indique echange a eu lieu*/
			}
		}
		len--;
	}
}
