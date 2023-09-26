#include "sort.h"

/**
 * shell_sort - uses shell_sort to sort an array
 * of integers in ascending order
 * @array: Array to be sorted
 * @size: Size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t n, i, j;
	int tmp;

	n = 1;
	while (n < size / 3)
		n = n * 3 + 1;

	while (n > 0)
	{
		i = n;
		while (i < size)
		{
			tmp = array[i];
			j = i;

			while (j >= n && array[j - n] > tmp)
			{
				array[j] = array[j - n];
				j = j - n;
			}

			array[j] = tmp;
			i++;
		}

		print_array(array, size);

		n /= 3;
	}
}
