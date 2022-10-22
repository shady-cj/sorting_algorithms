#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
   int array[] = {7, 19, 48, 99, 71, 13, 52, 96, 73, 86, 7, 100, 100, 10};
    /*int array[] = {1,2,3,4,5,6,6,6,6,7,8,8,8,8,9,9,9,9,9};*/
    /*int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};*/
    size_t n = sizeof(array) / sizeof(array[0]);

    print_array(array, n);
    printf("\n");
    shell_sort(array, n);
    printf("\n");
    print_array(array, n);
    return (0);
}
