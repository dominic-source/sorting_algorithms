#include "sort.h"

/**
 * selection_sort - sort a list using the selection sort algorithmi
 * @array: the array to sort
 * @size: the size of the array
 *
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, index;

	if (size < 2)
		return;
	for (i = 0; i < size; i++)
	{
		index = i;
		for (j = i; j < size; j++)
		{
			if (array[index] > array[j])
			{
				index = j;
			}
		}
		if (i != index)
		{
			array[i] ^= array[index];
			array[index] ^= array[i];
			array[i] ^= array[index];
			print_array(array, size);
		}
	}
}
