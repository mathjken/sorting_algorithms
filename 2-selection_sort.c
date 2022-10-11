#include "sort.h"

/**
 * swap - swaps two numbers
 * @n1: first number
 * @n2: second number
 */
void swap(int *n1, int *n2)
{
	int tmp;

	tmp = *n1;
	*n1 = *n2;
	*n2 =  tmp;
}

/**
 * selection_sort - sorts an array in ascending orde
 *
 * @array: array of integer
 * @size: number of elements in @array
 */
void selection_sort(int *array, size_t size)
{
	size_t x, z, small;

	for (x = 0; x < size - 1; x++)
	{
		small = x;
		for (z = x + 1; z < size; z++)
		{
			if (array[z] < array[small])
				small = z;
		}
		if (small != x)
		{
			swap(&array[small], &array[x]);
			print_array(array, size);
		}
	}
}
