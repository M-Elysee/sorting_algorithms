#include "sort.h"
/**
* selection_sort - sorts an array using seection array
* @array: points to the integer array
* @size: is the length of the array
*/
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int *small;
	int temp, k;

	if (size < 2 || array == NULL)
		return;
	for (i = 0; array[i] && i < size; i++)
	{
		small = array + i;
		k = 0;
		for (j = i + 1; array[j] && j < size; j++)
		{
			if (array[j] < *small)
			{
				small = array + j;
				k++;
			}
		}
		if (k != 0)
		{
			temp = array[i];
			array[i] = *small;
			*small = temp;
			print_array(array, size);
		}
	}
}
