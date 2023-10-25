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
 * partition - Order a subset of an array of integers according to
 *                    the lomuto partition scheme (last element as mid).
 * @array: The array of integers.
 * @sz: The size of the array.
 * @x: The starting index of the subset to order.
 * @y: The ending index of the subset to order.
 *
 * Return: The final partition index.
 */
int partition(int *array, size_t size, int x, int y)
{
	int *mid, up, down;

	mid = array + y;
	for (up = down = x; down < y; down++)
	{
		if (array[down] < *mid)
		{
			if (up < down)
			{
				swapping_ints(array + down, array + up);
				print_array(array, size);
			}
			up++;
		}
	}

	if (array[up] > *mid)
	{
		swapping_ints(array + up, mid);
		print_array(array, size);
	}

	return (up);
}

/**
 * sort - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @x: The starting index of the array partition to order.
 * @y: The ending index of the array partition to order.
 *
 * Description: Uses the Lomuto partition scheme.
 */
void sort(int *array, size_t size, int x, int y)
{
	int part;

	if (y - x > 0)
	{
		part = partition(array, size, x, y);
		sort(array, size, x, part - 1);
		sort(array, size, part + 1, y);
	}
}

/**
 * quick_sort - Sort an array of integers in ascending
 *              order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Lomuto partition scheme. Prints
 *              the array after each swap of two elements.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	sort(array, size, 0, size - 1);
}
