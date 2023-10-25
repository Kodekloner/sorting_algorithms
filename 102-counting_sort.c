#include "sort.h"

/**
 * counting_sort - Sort an array of integers in ascending order
 *                 using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the counting array after setting it up.
 */
void counting_sort(int *array, size_t size)
{
	int *cnt, *srt, mx, j;

	if (array == NULL || size < 2)
		return;

	srt = malloc(sizeof(int) * size);
	if (srt == NULL)
		return;
	mx = array[0];
	for (j = 1; j < (int)size; j++)
	{
		if (array[j] > mx)
			mx = array[j];
	}
	cnt = malloc(sizeof(int) * (mx + 1));
	if (cnt == NULL)
	{
		free(srt);
		return;
	}

	for (j = 0; j < (mx + 1); j++)
		cnt[j] = 0;
	for (j = 0; j < (int)size; j++)
		cnt[array[j]] += 1;
	for (j = 0; j < (mx + 1); j++)
		cnt[j] += cnt[j - 1];
	print_array(cnt, mx + 1);

	for (j = 0; j < (int)size; j++)
	{
		srt[cnt[array[j]] - 1] = array[j];
		cnt[array[j]] -= 1;
	}

	for (j = 0; j < (int)size; j++)
		array[j] = srt[j];

	free(srt);
	free(cnt);
}
