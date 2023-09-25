#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending
 * @array: input array
 * @size: array size
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int num1, num2;

	if (size < 2)
		return;
	i = 0;
	while (i < size - 1)
	{
		num1 = 0;
		j = 0;
		while (j < size - i - 1)
		{
			if (array[j] > array[j + 1])
			{
				num2 = array[j];
				array[j] = array[j + 1];
				array[j + 1] = num2;
				num1 = 1;
				print_array(array, size);
			}
			j++;
		}
		i++;
		if (num1 == 0)
			break;
	}
}
