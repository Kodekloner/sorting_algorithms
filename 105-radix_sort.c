#include "sort.h"

/**
 * gt_mx - Get the maximum value in an array of integers.
 * @arr: An array of integers.
 * @sz: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int gt_mx(int *arr, int sz)
{
	int max, i;

	for (max = arr[0], i = 1; i < sz; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}

	return (max);
}

/**
 * radix_counting_sort - Sort the significant digits of an array of integers
 *                       in ascending order using the counting sort algorithm.
 * @arr: An array of integers.
 * @sz: The size of the array.
 * @sign: The significant digit to sort on.
 * @buf: A buffer to store the sorted array.
 */
void radix_counting_sort(int *arr, size_t sz, int sign, int *buf)
{
	int count[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t i;

	for (i = 0; i < sz; i++)
		count[(arr[i] / sign) % 10] += 1;

	for (i = 0; i < 10; i++)
		count[i] += count[i - 1];

	for (i = sz - 1; (int)i >= 0; i--)
	{
		buf[count[(arr[i] / sign) % 10] - 1] = arr[i];
		count[(arr[i] / sign) % 10] -= 1;
	}

	for (i = 0; i < sz; i++)
		arr[i] = buf[i];
}

/**
 * radix_sort - Sort an array of integers in ascending
 *              order using the radix sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the LSD radix sort algorithm. Prints
 * the array after each significant digit increase.
 */
void radix_sort(int *array, size_t size)
{
	int max, sign, *buf;

	if (array == NULL || size < 2)
		return;

	buf = malloc(sizeof(int) * size);
	if (buf == NULL)
		return;

	max = gt_mx(array, size);
	for (sign = 1; max / sign > 0; sign *= 10)
	{
		radix_counting_sort(array, size, sign, buf);
		print_array(array, size);
	}

	free(buf);
}
