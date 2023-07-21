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
	size_t i, j, temp, exchange = 1;

	if (size < 2)
		return;
	for (i = 0; i < size; i++)
	{
		if (!exchange)
			break;
		exchange = 0;
		for (j = 0; j < (size - 1 - i); j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				exchange = 1;
				print_array(array, size);
			}
		}
	}
}

