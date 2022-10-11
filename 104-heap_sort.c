#include "sort.h"

/**
 * heap_tree - turns an array in a heap tree
 * @array: array to turn into heap
 * @s: size of the subtree
 * @root: index of the subtree in the heap
 * @size: size of the whole array
 */
void heap_tree(int *array, size_t s, size_t root, size_t size)
{
	size_t max, left, right;
	int tmp;

	max = root;
	left = (root * 2) + 1;
	right = (root * 2) + 2;

	if (left < s && array[left] > array[max])
		max = left;

	if (right < s && array[right] > array[max])
		max = right;

	if (max != root)
	{
		tmp = array[root];
		array[root] = array[max];
		array[max] = tmp;
		print_array(array, size);
		heapify(array, s, max, size);
	}
}

/**
 * heap_sort - sorts an array following the Heap sort algorithm
 * @array: array of ints to sort
 * @size: size of the array to sort
 */
void heap_sort(int *array, size_t size)
{
	int x, tmp;

	if (size < 2)
		return;

	for (x = size / 2 - 1; x >= 0; x--)
		heap_tree(array, size, (size_t)x, size);

	for (x = size - 1; x >= 0; x--)
	{
		tmp = array[x];
		array[x] = array[0];
		array[0] = tmp;
		if (x != 0)
			print_array(array, size);
		heap_tree(array, (size_t)x, 0, size);
	}
}
