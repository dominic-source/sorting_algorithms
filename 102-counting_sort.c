#include "sort.h"

/**
 * counting_sort - implement the count sort algorithm
 * @array: the array of integers which are each >= 0
 * @size: the size of the array
 */
void counting_sort(int *array, size_t size)
{
	/* Variable declarations */
	size_t i, j, k, maxVal = 0, key;
	int *arraytmp, *arrayhld;

	if (size < 2)
		return;
	/* find the maximum number */
	for (i = 0; i < size; i++)
		if ((size_t)array[i] > maxVal)
			maxVal = array[i];
	/* Allocate memory to have the size of the index 0 of the array + 1 */
	arraytmp = calloc(maxVal + 1, sizeof(int));
	if (arraytmp == NULL)
		return;
	arrayhld = calloc(size, sizeof(int));
	if (arrayhld == NULL)
	{
		free(arraytmp);
		return;
	}
	/* Create a loop that stores the count of each value of the array*/
	for (i = 0; i < size; i++)
		arraytmp[array[i]] += 1;

	/* sum up each individual index with it predecessor index */
	for (j = 1; j <= maxVal; j++)
		arraytmp[j] += arraytmp[j - 1];
	print_array(arraytmp, maxVal + 1);
	/*add the value of the array as the index */
	for (k = 0; k < size; k++)
	{
		key = array[k];
		arraytmp[key] -= 1;
		arrayhld[arraytmp[key]] = key;
	}
	for (i = 0; i < size; i++)
		array[i] = arrayhld[i];
	free(arraytmp);
	free(arrayhld);
}
