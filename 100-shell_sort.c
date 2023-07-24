#include "sort.h"

/**
 * shell_sort - sort an array integers using the shell sort algorithm
 * @array: the array of integers
 * @size: the length of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t i, j, gap = 1;
	int temp;

	/* Calculate the gap size using the knuth squence*/
	while (gap < size)
		gap = gap * 3 + 1;
	gap = (gap - 1) / 3;

	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			for (j = i; (j >= gap && (array[j - gap] > temp)); j -= gap)
				array[j] = array[j - gap];
			array[j] = temp;
		}
		gap = (gap - 1) / 3;
		print_array(array, size);
	}
}
