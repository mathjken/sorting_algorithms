#include "sort.h"

/**
 * swap - swaps two numbers
 * @num1: first number
 * @num2: second number
 */
void swap(int *n1, int *n2)
{
	int tmp = *n1;
	*n1 = *n2;
	*n2 = tmp;
}

/**
 * partition - find partiton position
 * @array: array of integer
 * @low: lower bound of array
 * @high: higher bound of array
 * @size: number of elements in @array
 *
 * Return: position of pivot
 */
int partition(int *array, int low, int high, size_t size)
{
	/* select the rightmost element as pivot */
	int pivot = array[high];
	/* pointer for greater element */
	int ptr = low, z;
	/*
	 *traverse across each element in array and
	 *compare them with pivot
	 */
	for (z = low; z < high; z++)
	{
		if (array[z] <= pivot)
		{
			if (ptr != z)
			{
				/*
				 * if element smaller than pivot is found
				 *swap it with the greater element
				 */
				swap(&array[ptr], &array[z]);
				print_array(array, size);
			}
			ptr++;
		}
	}
	if (ptr != high)
	{
		swap(&array[ptr], &array[high]);
		print_array(array, size);
	}
	return (ptr);
}

/**
 * quicksort - quick sort with recursion
 * @array: array of integer
 * @low: lower bound of array
 * @high: higher bound of array
 * @size: number of elements in @array
 */
void quicksort(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = partition(array, low, high, size);
		quicksort(array, low, pivot - 1, size);
		quicksort(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort - quick sorts an array
 * @array: array to sort
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksort(array, 0, size - 1, size);
}
