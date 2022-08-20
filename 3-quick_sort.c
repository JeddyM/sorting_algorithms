#include "sort.h"

/**
 * quick_sort - sorts an array of integers in ascending order using the Quick
 * sort algorithm. implementing the Lomuto partition scheme.
 * @array: array to sort
 * @size: array size
 */


void quick_sort(int *array, size_t size)
{


	if (array == NULL || size < 2)
		return;
	/*starting index = 0, while element on right index is size - 1*/
	quicksort_r(array, 0, size - 1, size);
}

/**
 * partition - lomuto partition last element as pivot
 * @array: array
 * @size : array size
 * @low: starting index of the partition to sort
 * @high: last index of partition to sort
 * Return: ordered partition
 */



int partition(int *array, int low, int high, size_t size)
{
	int i, temp;

	/*pivot is the element on the right most*/
	int pivot = array[high];
	/*pointer of greater element*/
	int j = (low - 1);

	for (i = low; i < high; i++)
	{
		if (array[i] < pivot)
		{
			j++;
			if (array[i] != array[j])
			{
				temp = array[j];
				array[j] = array[i];
				array[i] = temp;
				print_array(array, size);
			}
		}
	}
	if (array[j + 1] != array[high])
	{
		temp = array[j + 1];
		array[j + 1] = array[high];
		array[high] = temp;
		print_array(array, size);
	}
	return (j + 1);
}

/**
 * quicksort_r - implementing quick sort recursively
 * @array: array to sort
 * @size: array size
 * @low: starting index of the partition to sort
 * @high: last index of partition to sort
 */

void quicksort_r(int *array, int low, int high, size_t size)
{
	int part;

	if (high > low)
	{
		part = partition(array, low, high, size);
		quicksort_r(array, low, part - 1, size);
		quicksort_r(array, part + 1, high, size);
	}
}
