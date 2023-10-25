/*
 * File: 106-bitonic_sort.c
 * Auth: Brennan D Baraban
 */

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
 * btn_mrg - Sort a bitonic sequence inside an array of integers.
 * @arr: An array of integers.
 * @sz: The size of the array.
 * @strt: The starting index of the sequence in array to sort.
 * @sq: The size of the sequence to sort.
 * @flw: The direction to sort in.
 */
void btn_mrg(int *arr, size_t sz, size_t strt, size_t sq,
		char flw)
{
	size_t i, jump = sq / 2;

	if (sq > 1)
	{
		for (i = strt; i < strt + jump; i++)
		{
			if ((flw == TOP && arr[i] > arr[i + jump]) ||
			    (flw == BOTTOM && arr[i] < arr[i + jump]))
				swapping_ints(arr + i, arr + i + jump);
		}
		btn_mrg(arr, sz, strt, jump, flw);
		btn_mrg(arr, sz, strt + jump, jump, flw);
	}
}

/**
 * btnc_sq - Convert an array of integers into a bitonic sequence.
 * @arr: An array of integers.
 * @sz: The size of the arr.
 * @strt: The strting index of a block of the building bitonic sequence.
 * @sq: The size of a block of the building bitonic sequence.
 * @flw: The direction to sort the bitonic sequence block in.
 */
void btnc_sq(int *arr, size_t sz, size_t strt, size_t sq, char flw)
{
	size_t cut = sq / 2;
	char *str = (flw == TOP) ? "UP" : "DOWN";

	if (sq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", sq, sz, str);
		print_array(arr + strt, sq);

		btnc_sq(arr, sz, strt, cut, TOP);
		btnc_sq(arr, sz, strt + cut, cut, BOTTOM);
		btn_mrg(arr, sz, strt, sq, flw);

		printf("Result [%lu/%lu] (%s):\n", sq, sz, str);
		print_array(arr + strt, sq);
	}
}

/**
 * bitonic_sort - Sort an array of integers in ascending
 *                order using the bitonic sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap. Only works for
 * size = 2^k where k >= 0 (ie. size equal to powers of 2).
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	btnc_sq(array, size, 0, size, TOP);
}
