#include "sort.h"

/**
 * selection_sort - sorts using selection sort
 * @array: array of ints
 * @size: size of array
*/

void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;

	if (array == NULL || size < 2)
	{
		return;
	}
	for (i = 0; i < size; i++)
	{
		for (j = i; j < size; j++)
		{
			if (array[i] > array[j])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}
}
