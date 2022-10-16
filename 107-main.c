#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
   /* int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};*/
    int array[] = {79, 47, 68, 87, 84, 91, 21, 32, 34, 2, 95, 31, 20, 22, 98, 39, 92, 41, 62, 1};
  
    /*int array[] = {87, 65, 28, 63, 93, 52, 39, 59, 27, 30, 24, 83, 69, 62, 13, 6, 88, 58, 92, 26, 42, 11, 16, 21, 75, 36, 71, 8, 45, 38};*/
    size_t n = sizeof(array) / sizeof(array[0]);
                                                                                            print_array(array, n);                                                                  printf("\n");
    quick_sort_hoare(array, n);
    printf("\n");                                                                           print_array(array, n);                                                                  return (0);                                                                         }
