#include "sort.h"

/**
 * swapping_ints - Swap two integers in an array.
 * @x: The first integer to swap.
 * @y: The second integer to swap.
 */
void swapping_ints(int *x, int *y)
{
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

/**
 * mx_heap - Turn a binary tree into a complete binary heap.
 * @array: An array of integers representing a binary tree.
 * @sz: The size of the array/tree.
 * @bs: The index of the base row of the tree.
 * @rt: The root node of the binary tree.
 */
void mx_heap(int *array, size_t sz, size_t bs, size_t rt)
{
	size_t left, right, large;

	left = 2 * rt + 1;
	right = 2 * rt + 2;
	large = rt;

	if (left < bs && array[left] > array[large])
		large = left;
	if (right < bs && array[right] > array[large])
		large = right;

	if (large != rt)
	{
		swapping_ints(array + rt, array + large);
		print_array(array, sz);
		mx_heap(array, sz, bs, large);
	}
}

/**
 * heap_sort - Sort an array of integers in ascending
 *             order using the heap sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the sift-down heap sort
 * algorithm. Prints the array after each swap.
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
		mx_heap(array, size, size, i);

	for (i = size - 1; i > 0; i--)
	{
		swapping_ints(array, array + i);
		print_array(array, size);
		mx_heap(array, size, i, 0);
	}
}
