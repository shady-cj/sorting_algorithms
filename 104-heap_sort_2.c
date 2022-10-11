#include "sort.h"


/**
 * heap_sort - Sorting an array using heap sort...
 * Using heapify method
 * @array: The array to be sorted
 * @size: The size
 */

void heap_sort(int *array, size_t size)
{
	int node, left, right, pholder, switch_node;
	size_t i;

	i = size;

	while (i > 1)
	{
		node = i / 2;
		while (node > 0)
		{
			right = node * 2;
			left = right - 1;
			if ((size_t)right >= i || array[left] > array[right])
				switch_node = left;
			else
				switch_node = right;
			if (array[node - 1] < array[switch_node])
			{
				pholder = array[switch_node];
				array[switch_node] = array[node - 1];
				array[node - 1] = pholder;
				print_array(array, size);
			}
			node--;
		}
		pholder = array[node];
		array[node] = array[i - 1];
		array[i - 1] = pholder;
		print_array(array, size);
		i--;
	}
}
