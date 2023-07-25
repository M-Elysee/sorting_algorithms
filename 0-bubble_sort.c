#include "sort.h"
/**
* bubble_sort - sorts an array using bubble sort
* @array: points to an integer array
* @size: is the size of the array
*/
void bubble_sort(int *array, size_t size)
{
	size_t i, j, temp;

	if (size < 2 || array == NULL)
		return;
	for (i = 0; i < size; i++)
	{
		for (j = 0; array[j] && j < size; j++)
		{
			if (array[j + 1] && j + 1 < size && array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
			}
		}
	}
}
