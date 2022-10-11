#include "sort.h"


/**
 * heapify - An helper function that heapify
 * @array: The array to be heapified
 * @size: The total size of the array
 * @length: The length of the heap
 * @node: The current node
 * Return: void
 */

void heapify(int *array, int node, size_t length, size_t size)
{
	int left, right, switch_node, pholder;

	right = node * 2;
	left = right - 1;
	if ((size_t)left >= length)
		return;
	if ((size_t)right >= length || array[left] > array[right])
		switch_node = left;
	else
		switch_node = right;
	if (array[node - 1] < array[switch_node])
	{
		pholder = array[switch_node];
		array[switch_node] = array[node - 1];
		array[node - 1] = pholder;
		print_array(array, size);
		heapify(array, switch_node + 1, length, size);
	}
}

/**
 * heap_sort - Sorting an array using heap sort...
 * Using heapify method
 * @array: The array to be sorted
 * @size: The size
 */

void heap_sort(int *array, size_t size)
{
	int node, pholder;
	size_t i;

	i = size;
	while (i > 1)
	{
		node = i / 2;
		while (node > 0)
		{
			heapify(array, node, i, size);
			node--;
		}
		pholder = array[node];
		array[node] = array[i - 1];
		array[i - 1] = pholder;
		print_array(array, size);
		i--;
	}
}
