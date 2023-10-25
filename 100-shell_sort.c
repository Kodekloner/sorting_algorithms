#include "sort.h"

/**
 * shell_sort - Sort an array of integers in ascending
 *              order using the shell sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Knuth interval sequence.
 */
void shell_sort(int *array, size_t size)
{
	size_t gp, x, y;
	int temp;

	if (array == NULL || size < 2)
		return;

	for (gp = 1; gp < (size / 3);)
		gp = gp * 3 + 1;

	for (; gp >= 1; gp /= 3)
	{
		for (x = gp; x < size; x++)
		{
			y = x;
			while (y >= gp && array[y - gp] > array[y])
			{
				temp = array[y];
				array[y] = array[y - gp];
				array[y - gp] = temp;
				y -= gp;
			}
		}
		print_array(array, size);
	}
}
