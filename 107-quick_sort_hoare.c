#include "sort.h"

/**
 * partition2 - Divides the array into partitions
 * @array: the array of unsorted integers
 * @size: the size of the array
 *
 * Return: partition index
 *
 */
int partition2(int *array, int size)
{
	int pivot, i, j;

	array[(size / 2) - 1] ^= array[size - 1];
	array[size - 1] ^= array[(size / 2) - 1];
	array[(size / 2) - 1] ^= array[size - 1];

	pivot = array[(size / 2) - 1];

	i = -1;
	j = size;

	while (1)
	{
		i += 1;
		while (array[i] < pivot)
			i += 1;
		j -= 1;
		while (array[j] > pivot)
		j -= 1;

		if (i >= j)
			return (j);
		/* swap the element at the left and right indices */
		array[i] ^= array[j];
		array[j] ^= array[i];
		array[i] ^= array[j];
	}
}

/**
 * quick_sort_hoare2 - implement the quick sort algorithm
 * @array: the array of integers
 * @size: the size of the array
 * @oldarray: the original array of integers
 * @oldsize: the original size of the array
 */
void quick_sort_hoare2(int *array, size_t size, int *oldarray, size_t oldsize)
{
	size_t p_idx;

	if (size <= 1)
		return;
	p_idx = (size_t)partition2(array, (int)size);
	print_array(oldarray, oldsize);
	quick_sort_hoare2(array, p_idx + 1, oldarray, oldsize);
	quick_sort_hoare2(array + p_idx + 1, size - p_idx - 1, oldarray, oldsize);
}

/**
 * quick_sort_hoare - implement the quick sort algorithm
 * @array: the array of integers
 * @size: the size of the array
 *
 */
void quick_sort_hoare(int *array, size_t size)
{
	quick_sort_hoare2(array, size, array, size);
}
