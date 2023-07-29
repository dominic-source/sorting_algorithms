#include "sort.h"

/**
 * partition2 - Divides the array into partitions
 * @array: the array of unsorted integers
 * @low: the lower part of the array
 * @high: the higher part of the array
 *
 * Return: partition index
 *
 */
int partition2(int *array, int low, int high)
{
	int pivot, i, j;

	pivot = array[high - 1];
	i = low - 1;
	j = high + 1;
	while (1)
	{
		do
			i += 1;
		while (array[i] < pivot);

		do
			j -= 1;
		while (array[j] > pivot);

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
 * @low: the size of the array
 * @high: the original array of integers
 * @oldsize: the original size of the array
 */
void quick_sort_hoare2(int *array, int low, int high, int oldsize)
{
	int p_idx;

	if (low >= 0 && high >= 0 && low < high)
	{
		p_idx = partition2(array, low, high);
		print_array(array, oldsize);
		quick_sort_hoare2(array, low, p_idx, oldsize);
		quick_sort_hoare2(array, p_idx + 1, high, oldsize);
	}
}

/**
 * quick_sort_hoare - implement the quick sort algorithm
 * @array: the array of integers
 * @size: the size of the array
 *
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quick_sort_hoare2(array, 0, size - 1, (int)size);
}

