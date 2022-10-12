#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;



/**
 * struct k_gap_s - defining a doubly linked list
 * struct for the knuth_gap sequence
 * @n: The number in the sequence
 * @next: The next element in the linked list
 * @prev: The previous element in the list
 */

typedef struct k_gap_s
{
	size_t n;
	struct k_gap_s *next;
	struct k_gap_s *prev;
} k_gap_t;

void print_list(const listint_t *list);
void print_array(const int *array, size_t size);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
k_gap_t *knuth_gap(size_t size);
void free_gap(k_gap_t *head);
void sort(int *array, ssize_t lo, ssize_t hi, size_t size);
ssize_t partition(int *array, ssize_t st, ssize_t end, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
#endif
