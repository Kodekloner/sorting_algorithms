#include "sort.h"

/**
 * selection_sort - Sort an array of integers in ascending order
 *                  using the selection sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 */
void selection_sort(int *array, size_t size)
{
	int *mn;
	size_t x, y;

	if (array == NULL || size < 2)
		return;

	for (x = 0; x < size - 1; x++)
	{
		mn = array + x;
		for (y = x + 1; y < size; y++)
			mn = (array[y] < *mn) ? (array + y) : mn;

		if ((array + x) != mn)
		{
			int tmp = *(array + x);
			*(array + x) = *mn;
			*mn = tmp;
			print_array(array, size);
		}
	}
}
