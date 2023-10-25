#include "sort.h"

/**
 * mrge_sub_arr - Sort a subarray of integers.
 * @sub_arr: A subarray of an array of integers to sort.
 * @buf: A buffer to store the sorted subarray.
 * @fnt: The front index of the array.
 * @center: The middle index of the array.
 * @bck: The back index of the array.
 */
void mrge_sub_arr(int *sub_arr, int *buf, size_t fnt, size_t center,
		size_t bck)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(sub_arr + fnt, center - fnt);

	printf("[right]: ");
	print_array(sub_arr + center, bck - center);

	for (i = fnt, j = center; i < center && j < bck; k++)
		buf[k] = (sub_arr[i] < sub_arr[j]) ? sub_arr[i++] : sub_arr[j++];
	for (; i < center; i++)
		buf[k++] = sub_arr[i];
	for (; j < bck; j++)
		buf[k++] = sub_arr[j];
	for (i = fnt, k = 0; i < bck; i++)
		sub_arr[i] = buf[k++];

	printf("[Done]: ");
	print_array(sub_arr + fnt, bck - fnt);
}

/**
 * mrge_srt_recurse - Implement the merge sort algorithm through recursion.
 * @sub_arr: A subarray of an array of integers to sort.
 * @buf: A buffer to store the sorted result.
 * @fnt: The front index of the subarray.
 * @bck: The back index of the subarray.
 */
void mrge_srt_recurse(int *sub_arr, int *buf, size_t fnt, size_t bck)
{
	size_t center;

	if (bck - fnt > 1)
	{
		center = fnt + (bck - fnt) / 2;
		mrge_srt_recurse(sub_arr, buf, fnt, center);
		mrge_srt_recurse(sub_arr, buf, center, bck);
		mrge_sub_arr(sub_arr, buf, fnt, center, bck);
	}
}

/**
 * merge_sort - Sort an array of integers in ascending
 *              order using the merge sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the top-down merge sort algorithm.
 */
void merge_sort(int *array, size_t size)
{
	int *buf;

	if (array == NULL || size < 2)
		return;

	buf = malloc(sizeof(int) * size);
	if (buf == NULL)
		return;

	mrge_srt_recurse(array, buf, 0, size);

	free(buf);
}
