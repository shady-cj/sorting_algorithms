#include "sort.h"


/**
 * partition - This helper function partitions the
 * array an place a picked pivot using lomuto
 * partition scheme in its sorted position
 * @array: The array
 * @st: The start index
 * @end: The end index
 * @size: The size of the array this is required
 * for printing the array at every swap
 * Return: The sorted index of the pivot
 */
ssize_t partition(int *array, ssize_t st, ssize_t end, size_t size)
{
	ssize_t i, j, pivot;
	int pl;

	pivot = end;
	j = st;
	i = j - 1;
	while (j < pivot)
	{
		if (array[j] <= array[pivot])
		{
			i++;
			pl = array[i];
			array[i] = array[j];
			array[j] = pl;
			if (i != j)
				print_array(array, size);
		}
		j++;
	}
	pl = array[i + 1];
	array[i + 1] = array[pivot];
	array[pivot] = pl;
	if (i + 1 != pivot)
		print_array(array, size);
	return (i + 1);
}


/**
 * sort - A function that is called to perform
 * quick sort
 * @array: The array to be sorted
 * @lo: The start index
 * @hi: The end index
 * @size: The size of the array... this is required for
 * printing the array
 * Return: void
 */

void sort(int *array, ssize_t lo, ssize_t hi, size_t size)
{
	ssize_t sorted_index;

	if (lo >= hi)
		return;
	sorted_index = partition(array, lo, hi, size);
	sort(array, lo, sorted_index - 1, size);
	sort(array, sorted_index + 1, hi, size);
}



/**
 * quick_sort - Implementation of the quick sort
 * algorithm to sort an array of numbers
 * @array: Array of numbers to be sorted
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	sort(array, 0, (size - 1), size);
}
