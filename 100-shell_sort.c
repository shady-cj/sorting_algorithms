#include "sort.h"

typedef struct k_gap_s {
	size_t n;
	struct k_gap_s *next;
	struct k_gap_s *prev;
} k_gap_t;


/**
 * knuth_gap - Implementing knuth gap sequence
 * @size: The size of the array
 * Return: an array containing the sequence based on
 * the size of the array
 */

k_gap_t *knuth_gap(size_t size)
{
	k_gap_t *ptr, *new;
	size_t seq, i = 1, j, pow;

	seq = 1;
	ptr = NULL;
	while (seq <= size)
	{
		new = malloc(sizeof(k_gap_t));
		if (!new)
			return (NULL);
		new->n = seq;
		if (ptr)
			ptr->next = new;
		new->prev = ptr;
		new->next = NULL;
		ptr = new;
		i++;
		j = 0;
		pow = 1;
		while (j++ < i)
			pow *= 3;
		seq = (pow - 1) / 2;
	}
	return (ptr);
}

/**
 * shell_sort - Using shell sort sorting algorithm
 * to sort the array
 * @array: The array to be sorted
 * @size: The size of the array
 */

void shell_sort(int *array, size_t size)
{
	k_gap_t *ptr;
	size_t i, j, cur;
	ssize_t prev;
	int pl;

	if (array == NULL || size == 0)
		return;
	ptr = knuth_gap(size);
	while (ptr)
	{
		i = 0;
		while (i < ptr->n)
		{
			j = i;
			while (j < size)
			{
				cur = j;
				prev = j - ptr->n;
				while (prev >= 0)
				{
					if (array[cur] < array[prev])
					{
						pl = array[cur];
						array[cur] = array[prev];
						array[prev] = pl;
					}
					else
					{
						break;
					}
					cur = prev;
					prev = prev - ptr->n;
				}
				j += ptr->n;
			}
			i++;
		}
		ptr = ptr->prev;
		print_array(array, size);
	}
}
