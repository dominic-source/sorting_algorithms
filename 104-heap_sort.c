#include "sort.h"

/**
 * siftDown - this function is used to build the maximum heap
 * @array: the array of integers
 * @start: the beginning of the array
 * @end: the end of the array to siftdown
 * @size: the size was added specifically for printing
*/
void siftDown(int **array, int start, int end, int size)
{
	int root, iLeftChild, swap, child;

	root = start;
	iLeftChild = 2 * root + 1;

	while (iLeftChild <= end)
	{
		child = iLeftChild;
		swap = root;

		if ((*array)[swap] < (*array)[child])
			swap = child;
		if ((child + 1) <= end && (*array)[swap] < (*array)[child + 1])
			swap = child + 1;
		if (swap == root)
			return;
		else if (swap != root)
		{
			/* Swap the child and it parent */
			(*array)[root] ^= (*array)[swap];
			(*array)[swap] ^= (*array)[root];
			(*array)[root] ^= (*array)[swap];
			print_array(*array, size);
			/* repeat the same process until child greater than end */
			siftDown(array, swap, end, size);
		}
	}
}


/**
 * heapify - heapify will put element in the array in heap order
 * @array: the array of element
 * @size: the size of the array
 */
void heapify(int **array, size_t size)
{
	int start;

	start = (size / 2) - 1;

	while (start >= 0)
	{
		siftDown(array, start, size - 1, size);
		--start;
	}
}

/**
 * heap_sort - implement the head sort algorithm
 * @array: the array of the unsorted integers
 * @size: the size of the array
 *
 */
void heap_sort(int *array, size_t size)
{
	size_t end;
	
	if (size < 2)
		return;
	heapify(&array, size);
	end = size - 1;

	while (end > 0)
	{
		/* swap the array[end] with array[0] */
		array[end] ^= array[0];
		array[0] ^= array[end];
		array[end] ^= array[0];
		print_array(array, size);
		--end;
		siftDown(&array, 0, end, size);
	}
}

