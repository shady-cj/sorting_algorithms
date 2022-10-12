#include "sort.h"

/**
 * bitonicMerge - The bitonic Merge merges two parts
 * of the array based on the @dir of the bitonic sequence
 * @array: The main array
 * @lo: The starting index
 * @hi: The new high to be sorted
 * @size: The size of the main array
 * @dir: The direction to be sorted in. 1 for up
 * and 0 for down
 */

void bitonicMerge(int *array, size_t lo, size_t hi,
		size_t size, int dir)
{
	size_t i, j, mid;
	int pholder;

	if ((hi - lo) == 1)
		return;
	mid = (lo + hi) / 2;
	for (i = lo, j = mid; j < hi; i++, j++)
	{
		if ((dir && array[i] > array[j]) ||
			(!dir && array[i] < array[j]))
		{
			pholder = array[i];
			array[i] = array[j];
			array[j] = pholder;
		}
	}
	bitonicMerge(array, lo, mid, size, dir);
	bitonicMerge(array, mid, hi, size, dir);
}

/**
 * bitonicSort - The recursive function that splits
 * the array to turn into bitonic sequence
 * @lo: The starting index
 * @hi: The new high
 * @size: The size of the array
 * @dir: The direction of the array 1 for ascending
 * and 0 for descending
 */
void bitonicSort(int *array, size_t lo, size_t hi,
		size_t size, int dir)
{
	size_t mid, i;
	int *new_arr;

	if ((hi - lo) == 1)
		return;
	mid = (hi + lo) / 2;
	new_arr = malloc(sizeof(int) * (hi - lo));
	for (i = 0; i < (hi - lo); i++)
		new_arr[i] = array[i + lo];
	if (dir)
		printf("Merging [%lu/%lu] (UP):\n", hi - lo, size);
	else
		printf("Merging [%lu/%lu] (DOWN):\n", hi - lo, size);
	print_array(new_arr, (hi - lo));
	bitonicSort(array, lo, mid, size, 1);
	bitonicSort(array, mid, hi, size, 0);
	bitonicMerge(array, lo, hi, size, dir);
	for (i = 0; i < (hi - lo); i++)
		new_arr[i] = array[i + lo];
	if (dir)
		printf("Result [%lu/%lu] (UP):\n", hi - lo, size);
	else
		printf("Result [%lu/%lu] (DOWN):\n", hi - lo, size);
	print_array(new_arr, (hi - lo));
	free(new_arr);
}


/**
 * bitonic_sort - Sorts an array using bitonic sort..
 * @array: The array to be sorted
 * @size: The size of the array
 */


void bitonic_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	bitonicSort(array, 0, size, size, 1);
}
