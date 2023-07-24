#include "sort.h"

/**
 * swap_array - Swap two integers in an array.
 * @a: first integer to swap
 * @b: second integer to swap
 */
void swap_array(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * partition - Sort a subset of an array of integers
 *
 * @array: array of integers
 * @size: size of the array
 * @low: begining index of the subset to sort
 * @high: last index of the subset to sort
 *
 * Return: pivot index
 */
int partition(int *array, size_t size, int low, int high)
{
	int *pivot, above, below;

	pivot = array + high;
	for (above = below = low; below < high; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap_array(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap_array(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}


/**
 * sort - Implement the quicksort algorithm (lomuto)
 *
 * @array: An array of integers to sort
 * @size: The size of the array
 * @low: begining index of the array partition to sort
 * @high: last index of the array partition to sort
 *
 */
void sort(int *array, size_t size, int low, int high)
{
	int split;

	if (high - low > 0)
	{
		split = partition(array, size, low, high);
		sort(array, size, low, split - 1);
		sort(array, size, split, high);
	}
}

/**
 * quick_sort - Sorts an array of integers using Lomuto
 *
 * @array: A pointer to an array of integers
 * @size: Size of the array
*/
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	sort(array, size, 0, size - 1);
}
