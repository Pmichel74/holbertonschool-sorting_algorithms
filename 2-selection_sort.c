#include <stdio.h>

/**
 * selection_sort - sorts an array of integers
 * @array: array to sort
 * @size: size of array
 */
void selection_sort(int *array, size_t size)
{
	size_t n1, n2;
	int temp;

	/*parcourt début jusqu'a l'avant dernier*/
	for (n1 = 0; n1 < size - 1; n1++)
	{
		/*min initialisé à l'indice du premier élément non trié.*/
		size_t min = n1;
		/*cherche le + petit élément dans la partie non triée du tableau*/
		for (n2 = n1 + 1; n2 < size; n2++)
		{
			if (array[n2] < array[min])
			min = n2;
			continue;

		}
		if (min != n1)/*si +petit element pas à sa place*/
		{
			temp = array[n1];
			/*échange entre l'élément à la posiion first et le + petit élément*/
			array[n1] = array[min];
			/*Place ancien élément de first à position où était le + petit élém*/
			array[min] = temp;
			print_array(array, size);
		}
	}
}
