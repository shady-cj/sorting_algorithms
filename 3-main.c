#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    /*int array[] = {7, 19, 48, 99, 71, 13, 52, 96, 73, 86, 7, 100, 100, 10};*/
    /* int array[] = {1,2,3,4,5,6,6,6,6,7,8,8,8,8,9,9,9,9,9};*/
    /*int array[] = {5,4,7,6,2,2,6};*/
    int array[] = {79, 47, 68, 87, 84, 91, 21, 32, 34, 2, 95, 31, 20, 22, 98, 39, 92, 41, 62, 1};
    size_t n = sizeof(array) / sizeof(array[0]);

    print_array(array, n);
    printf("\n");
    quick_sort(array, n);
    printf("\n");
    print_array(array, n);
    return (0);
}
