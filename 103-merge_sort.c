#include "sort.h"

/**
 * merge - An helper function that implements the
 * merge sort algorithm using recursion
 * @array: The array to be sorted
 * @lo: The start
 * @hi: The end
 */
int *merge(int *array, ssize_t lo, ssize_t hi)
{
	ssize_t mid, i, j, t;
	int *left, *right, *main;

	main = malloc(sizeof(int) * ((hi - lo) + 1));
	if (hi - lo == 1)
	{
		main[0] = array[lo];
		return (main);
	}
	mid = (lo + hi) / 2;
	left = merge(array, lo, mid);
	right = merge(array, mid, hi);
	i = 0;
	j = 0;
	t = 0;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(left, (mid - lo));
	printf("[right]: ");
	print_array(right, (hi - mid));
	while (i < (mid - lo) && j < (hi - mid))
	{
		if (left[i] <= right[j])
			main[t] = left[i++];
		else
			main[t] = right[j++];
		t++;
	}
	while (i < (mid - lo))
		main[t++] = left[i++];
	while (j < (hi - mid))
		main[t++] = right[j++];
	free(left);
	free(right);
	printf("[Done]: ");
	print_array(main, (hi - lo));
	return (main);
}
/**
 * merge_sort - Sorting array using merge sort
 * @array - The array to be sorted
 * @size: The size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *a;
	size_t i;

	if (!array || size < 2)
		return;
	a = merge(array, 0, size);

	for (i = 0; i < size; i++)
		array[i] = a[i];
	free(a);
}
