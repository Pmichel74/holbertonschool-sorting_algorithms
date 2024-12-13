#include "sort.h"

/**
 * lomuto_partition - Partitions the array using the Lomuto scheme
 * @array: The array to be partitioned
 * @low: The starting index of the partition
 * @high: The ending index of the partition
 * @size: The total size of the array
 *
 * Return: The index of the pivot after partitioning
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];  /* Choix du pivot (dernier élément) */
	int i = low - 1;  /* Index du plus petit élément */
	int j, temp;

	for (j = low; j < high; j++)
	{
		/* Si l'élément courant est plus petit que le pivot */
		if (array[j] < pivot)
		{
			i++;  /* Incrémente l'index du plus petit élément */
			if (i != j)
			{
				/* Échange array[i] et array[j] */
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}

    /* Place le pivot à sa position correcte */
	if (i + 1 != high)
	{
		/* Échange array[i + 1] et array[high] */
		temp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = temp;
		print_array(array, size);
	}

    return (i + 1);
}

/**
 * quicksort - recursively sorts array of integers by separating into two
 * partitions, using Lomuto quick sort
 * @array: array of integers to be sorted
 * @low: index in array that begins partition
 * @high: index in array that ends partition
 * @size: amount of elements in array
 */
void quicksort(int *array, int low, int high, size_t size)
{
	int p;

	if (low < high)
	{
		p = lomuto_partition(array, low, high, size);
		quicksort(array, low, p - 1, size);/*partie gauche du pivot */
		quicksort(array, p + 1, high, size);/*partie droite du pivot*/
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order using a quick
 * sort algorithm, with Lomuto partition scheme
 * @array: array of integers to be sorted
 * @size: amount of elements in array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quicksort(array, 0, (int)size - 1, size);
}
