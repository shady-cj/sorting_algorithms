#include "sort.h"



/**
 * selection_sort - Sorting an array using selection sort sorting
 * algorithm
 * @array: The array to sort
 * @size: The size of the array
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, sm_index;
	ssize_t current_item;

	i = 0;
	while (i < size)
	{
		sm_index = i;
		
		j = i + 1;
		while (j < size)
		{
			if (array[j] < array[sm_index])
				sm_index = j;
			j++;
		}
		if (i != sm_index)
		{
			current_item = array[i];
			array[i] = array[sm_index];
			array[sm_index] = current_item;
			print_array(array, size);
		}
		i++;
	}
}
