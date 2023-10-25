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
 * hr_prtt - Order a subset of an array of integers
 *                   according to the hoare partition scheme.
 * @arr: The array of integers.
 * @size: The size of the array.
 * @left: The starting index of the subset to order.
 * @right: The ending index of the subset to order.
 *
 * Return: The final partition index.
 *
 * Description: Uses the last element of the partition as the pivot.
 * Prints the array after each swap of two elements.
 */
int hr_prtt(int *arr, size_t size, int left, int right)
{
	int pivot, above, below;

	pivot = arr[right];
	for (above = left - 1, below = right + 1; above < below;)
	{
		do {
			above++;
		} while (arr[above] < pivot);
		do {
			below--;
		} while (arr[below] > pivot);

		if (above < below)
		{
			swapping_ints(arr + above, arr + below);
			print_array(arr, size);
		}
	}

	return (above);
}

/**
 * hoare_sort - Implement the quicksort algorithm through recursion.
 * @arr: An array of integers to sort.
 * @size: The size of the array.
 * @left: The starting index of the array partition to order.
 * @right: The ending index of the array partition to order.
 *
 * Description: Uses the Hoare partition scheme.
 */
void hoare_sort(int *arr, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = hr_prtt(arr, size, left, right);
		hoare_sort(arr, size, left, part - 1);
		hoare_sort(arr, size, part, right);
	}
}

/**
 * quick_sort_hoare - Sort an array of integers in ascending
 *                    order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Hoare partition scheme. Prints
 * the array after each swap of two elements.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}
