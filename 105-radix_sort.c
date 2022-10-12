#include "sort.h"

/**
 * radix - a recursive function that carries out the radix
 * sort by recursively apply counting sort to each unit of
 * the array
 * @array: The array
 * @array_copy: The copy of the array
 * @unit: The current unit or significant digit e.g
 * tens, hundreds
 * @largest: the largest element in the array
 * @size: The size of the arrays
 */
void radix(int *array, int *array_copy, int largest, int unit,
		size_t size)
{
	int last_digit, i, real_idx;
	size_t idx;
	int *count_array;

	if ((largest / unit) == 0)
		return;
	count_array = malloc(sizeof(int) * 10);
	for (i = 0; i < 10; i++)
		count_array[i] = 0;
	for (idx = 0; idx < size; idx++)
	{
		last_digit = (array[idx] / unit) % 10;
		count_array[last_digit] += 1;
	}
	for (i = 1; i < 10; i++)
		count_array[i] += count_array[i - 1];
	for (idx = size - 1; (int)idx >= 0; idx--)
	{
		last_digit = (array_copy[idx] / unit) % 10;
		real_idx = --count_array[last_digit];
		array[real_idx] = array_copy[idx];
	}
	for (idx = 0; idx < size; idx++)
		array_copy[idx] = array[idx];
	free(count_array);
	print_array(array, size);
	radix(array, array_copy, largest, unit * 10, size);
}


/**
 * radix_sort - Sorting an array using radix sort
 * @array: The array to be sorted
 * @size: The size of the array
 */

void radix_sort(int *array, size_t size)
{
	int largest;
	int *array_copy;
	size_t i = 0;

	if (!array || size < 2)
		return;
	array_copy = malloc(sizeof(int) * size);
	largest = 0;
	while (i < size)
	{
		array_copy[i] = array[i];
		if (array[i] > largest)
			largest = array[i];
		i++;
	}
	radix(array, array_copy, largest, 1, size);
	free(array_copy);
}
