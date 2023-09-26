#include "sort.h"

/**
 * swap - swaps the values of two variables
 * @x: pointer to a variable
 * @y: pointer to a variable
 */
void swap(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

/**
 * lomuto_partition - uses lomunto scheme to partition array
 * @array: input array
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: array size
 *
 * Return: Index of the pivot element
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot, i, j;

	pivot = array[high];
	i = low - 1;
	j = low;

	while (j <= high - 1)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(&array[i], &array[j]);
			print_array(array, size);
		}
		j++;
	}
	swap(&array[i + 1], &array[high]);
	print_array(array, size);
	return (i + 1);
}

/**
 * quick_sort_recursive - Recursive function for quicksort
 * @array: input array
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Size of the array
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot_index;

		pivot_index = lomuto_partition(array, low, high, size);
		quick_sort_recursive(array, low, pivot_index - 1, size);
		quick_sort_recursive(array, pivot_index + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick sort
 * @array: Array to be sorted
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		exit(EXIT_FAILURE);

	quick_sort_recursive(array, 0, size - 1, size);
}
