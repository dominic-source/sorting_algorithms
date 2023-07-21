#include "sort.h"

/**
 * bubble_sort - an algorith to sort an array of integers
 *
 * @array: the array of integers
 * @size: the size of the array
 *
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j, exchange = 1;

	if (size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		exchange = 0;
		for (j = 0; j < (size - 1 - i); j++)
		{
			if (array[j] > array[j + 1])
			{
				array[j] ^= array[j + 1];
				array[j + 1] ^= array[j];
				array[j] ^= array[j + 1];
				exchange = 1;
				print_array(array, size);
			}
		}
		if (!exchange)
			break;
	}
}

