#include "sort.h"

/**
 * partition - Divides the array into partitions
 * @array: the array of unsorted integers
 * @low: the left side of the array
 * @high: the right side of the array
 * 
 * Return: partition index
 *
 */
int partition(int *array, int low, int high)
{
	int pivot, i, j;

	pivot = array[high];

	i = low - 1;
	j = high + 1;

	while (true)
	{
		while (array[i] < pivot)
			++i;
		while (array[j] > pivot)
			--J;
		if (i >= j)
			return (j);
		/* swap the element at the left and right indices */
		array[i] ^= array[j];
		array[j] ^= array[i];
		array[i] ^= array[j];	
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
	
	if 

}
