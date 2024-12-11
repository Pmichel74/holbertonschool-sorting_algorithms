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
		swap = 0;
		for (i = 0; i < len - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				tmp = array[i + 1];
				array[i + 1] = array[i];
				array[i] = tmp;
				print_array(array, size);
				swap = 1;
			}
		}
		len--;
		if (!swap)
			break;
	}
}
