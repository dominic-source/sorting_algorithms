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
	size_t i, j, now, later, temp, exchange = 1;

	for (i = 0; i < size; i++)
	{
		if (!exchange)
			break;
		exchange = 0;
		for (j = 0; j < (size - 1); j++)
		{
			now = array[j];
			later = array[j + 1];
			if (now > later)
			{
				temp = now;
				array[j] = later;
				array[j + 1] = temp;
				exchange = 1;
				print_array(array, size);
			}
			else if (exchange == 0)
				exchange = 0;
		}
	}
}
