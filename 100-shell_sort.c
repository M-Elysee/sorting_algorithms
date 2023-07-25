#include "sort.h"
/**
* shell_sort - sort an array using shell sort argorithm
* @array: points to an integer array to be sorted
* @size: is the length of the array
*/
void shell_sort(int *array, size_t size)
{
	size_t i, k, n, temp;

	if (!array || size < 2)
		return;
	for (i = 1; i < (size / 3);)
		i = (i * 3) + 1;
	for (; i >= 1; i /= 3)
	{
		for (k = i; k < size; k++)
		{
			n = k;
			while (n >= i && array[n - i] > array[n])
			{
				temp = array[n];
				array[n] = array[n - i];
				array[n - i] = temp;
				n -= i;
			}
		}
		print_array(array, size);
	}
}
