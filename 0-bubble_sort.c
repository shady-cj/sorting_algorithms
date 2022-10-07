#include "sort.h"


/**
 * bubble_sort - Implementing the bubble sort algorithm.
 * @array: The array to sort
 * @size: The size of the array
 * Return: void
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	ssize_t placeholder;

	for (i = 0; i < (size - 1); i++)
	{
		for (j = 0; j < (size - 1); j++)
		{
			if (array[j] > array[j + 1])
			{
				placeholder = array[j];
				array[j] = array[j + 1];
				array[j + 1] = placeholder;
				print_array(array, size);
			}
		}
	}
}
