#include "sort.h"

/**
 * merge_sub - merges subarrays
 * @arr: allocated memory for arrays
 * @array: array to merge
 * @low: index of the left most element
 * @pivot: index of the middle element
 * @high: index of the right most element
 */
void merge_subarray(int *arr, int *array, size_t low,
		size_t pivot, size_t high)
{
	size_t i, j, k = 0;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + low, pivot  - low);
	printf("[right]: ");
	print_array(array + pivot, high - pivot);

	for (i = low, j = pivot; i < pivot && j < high; k++)
	{
		if (array[i] < array[j])
			arr[k] = array[i++];
		else
			arr[k] = array[j++];
	}

	while (i < pivot)
		arr[k++] = array[i++];
	while (j < high)
		arr[k++] = array[j++];

	for (k = low, i = 0; k < high; k++)
		array[k] = arr[i++];

	printf("[Done]: ");
	print_array(array + low, high - low);
}

/**
 * merge_recursion - function that sorts an array using merge sort
 * @arr: allocated memory to copy array
 * @array: array to sort
 * @low: index of the left most element
 * @high: index of the right most element
 */
void merge_recursion(int *arr, int *array, size_t low, size_t high)
{
	size_t pivot;

	if (high - low > 1)
	{
		pivot = (high - low) / 2 + low;
		merge_recursion(arr, array, low, pivot);
		merge_recursion(arr, array, pivot, high);
		merge_subarray(arr, array, low, pivot, high);
	}
}

/**
 * merge_sort - sorts an array with the Merge Sort algorithm
 * @array: array of ints to sort
 * @size: size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *arr;

	if (!array || size < 2)
		return;

	arr = malloc(sizeof(int) * size);

	merge_recursion(arr, array, 0, size);
	free(arr);
}

