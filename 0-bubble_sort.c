#include "sort.h"
#include <stdbool.h>

/**
 * bubble_sort - sorts an array in ascending order
 *
 * @array: pointer to array to be sorted
 *
 * @size: size of array
 *
 * Return: void
 *
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j = 0;

	if (array == NULL)
		return;


	for (i = 0; i < size; i++)
	{
		bool sorted = false;

		do {
		sorted = false;

		for (j = 0; j < (size - 1 - i); j++)
		{
			if (array[j] > array[j + 1])
			{
				int temp;

				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				sorted = true;
				print_array(array, size);
			}
		}
		} while (sorted);
	}
}
