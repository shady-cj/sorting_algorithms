#include "sort.h"

/**
 * counting_sort - Implementing counting sort to sort an
 * array
 * @array: The array
 * @size: The size of the array
 */

void counting_sort(int *array, size_t size)
{
	int *count_array, *array_copy, largest, j, id;
	size_t i;

	array_copy = malloc(sizeof(int) * size);
	i = 0;
	largest = 0;
	while (i < size)
	{
		array_copy[i] = array[i];
		if (array[i] > largest)
			largest = array[i];
		i++;
	}
	j = 0;
	count_array = malloc(sizeof(int) * (++largest));
	while (j < largest)
		count_array[j++] = 0;
	i = 0;
	while (i < size)
		count_array[array[i++]]++;
	for (j = 1; j < largest; j++)
		count_array[j] += count_array[j - 1];
	print_array(count_array, largest);
	for (i = size - 1; (int)i >= 0; i--)
	{
		id = array_copy[i];
		count_array[id]--;
		array[count_array[id]] = id;
	}
	free(array_copy);
	free(count_array);
}
