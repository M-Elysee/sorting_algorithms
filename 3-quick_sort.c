#include "sort.h"
int lomuto_section(int *array, size_t size, int left_p, int right_p);
void lomuto_sort(int *array, size_t size, int left_p, int right_p);
/**
* lomuto_section - order a subset of an array using lomuto partition scheme
* @array: points to the array to be sorted
* @size: is the length of the array
* @left_p: is the starting position of the subset to be orded
* @right_p: is the end position of the subset to be odered
* Return: the final partition index
*/
int lomuto_section(int *array, size_t size, int left_p, int right_p)
{
	int *top, i, j, temp;

	top = array + right_p;
	for (i = j = left_p; j < right_p; j++)
	{
		if (array[j] < *top)
		{
			if (i < j)
			{
				temp = *(array + j);
				*(array + j) = *(array + i);
				*(array + i) = temp;
				print_array(array, size);
			}
			i++;
		}
	}
	if (array[i] > *top)
	{
		temp = array[i];
		array[i] = *top;
		*top = temp;
		print_array(array, size);
	}
	return (i);
}
/**
* lomuto_sort - sort an array using quicksort argorithm
* @array: points to the array to be sorted
* @size: is the length of the array
* @left_p: is the starting position of the array subset
* @right_p: si the end position of the array subset
*/
void lomuto_sort(int *array, size_t size, int left_p, int right_p)
{
	int i;

	if (right_p - left_p > 0)
	{
		i = lomuto_section(array, size, left_p, right_p);
		lomuto_sort(array, size, left_p, i - 1);
		lomuto_sort(array, size, i + 1, right_p);
	}
}
/**
* quick_sort - sort an array using quick sort argorithm
* @array: points to the array to be sorted
* @size: is the size of the array
*/
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	lomuto_sort(array, size, 0, size - 1);
}
