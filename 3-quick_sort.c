#include <stddef.h>
#include "sort.h"

/**
 * swap - swaps two integers
 *
 * @num1: pointer to first int
 *
 * @num2: pointer to second int
 *
 * Return: void
 *
 */

void swap(int *num1, int *num2)
{
	int temp;

	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

/**
 * partition - partitions the array while
 * referencing the pivot value
 *
 * @array: pointer to array to be sorted
 *
 * @size: size of array
 *
 * @low: lower partition
 *
 * @high: higher partition
 *
 * Return: value of i
 *
 */

int partition(int *array, size_t size, int low, int high)
{
	int pivot_value, i, j;

	pivot_value = array[high];
	i = low;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot_value)
		{
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
			i++;
		}
	}

	if (pivot_value != array[i])
	{
		swap(&array[i], &array[high]);
		print_array(array, size);
	}

	return (i);

}

/**
 * quicksort_recursion - recursively performs sorting
 *
 * @array: array to be sorted
 *
 * @size: size of array
 *
 * @low: lower partition
 *
 * @high: higher partition
 *
 * Return: void
 *
 */

void quicksort_recursion(int *array, size_t size, int low, int high)
{
	int pivot_index;

	if (low < high)
	{
		pivot_index = partition(array, size, low, high);
		quicksort_recursion(array, size, low, pivot_index - 1);
		quicksort_recursion(array, size, pivot_index + 1, high);
	}
}

/**
 * quick_sort - sorts an array using
 * quicksort algorithm
 *
 * @array: array to be sorted
 *
 * @size: size of array
 *
 * Return: void
 *
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL)
		return;

	quicksort_recursion(array, size, 0, size - 1);
}

