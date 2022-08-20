#include "sort.h"




/**
 * selection_sort - sorts an array of integers in ascending
 * order using the Selection sort algorithm
 * @array: array to sort
 * @size: size of array
 * Return: void
 */


void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int temp, min_idx;


	if (array == NULL || size == 0)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;
		/*travesring the array searching for min*/
		for (j = i + 1; j < size; j++)
		{
			if (array[min_idx] > array[j])
				min_idx = j;
		}
		/*swapping*/
		if (array[min_idx] != array[i])
		{
			temp = array[i];
			array[i] = array[min_idx];
			array[min_idx] = temp;
			print_array(array, size);
		}
	}
}
