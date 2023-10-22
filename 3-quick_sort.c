#include "sort.h"

/**
 * partition - partition func
 * @start: start
 * @end: end
 *
 * Return: pos of element
 */
int partition(int *array, int start, int end)
{
	int pivot;
	int i, j, temp;

	i = start - 1;
	pivot = array[end];
	for (j = start; j <= end - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			temp = array[i];
			array[i] = array[j];

			array[j] = temp;


		}
	}
	i++;
	temp = array[i];
	array[i] = array[end];

	array[end] = temp;
	return (i);
}
/**
 * @array: my array
 * @start: start of the array
 * @end: end of the array
 *
 * Return: no return
 */
void quick(int *array, int start, int end)
{
	int pivot;
	if (end <= start)
	{
		return;
	}

	pivot = partition(array, start, end);
	quick(array, start, pivot - 1);
	quick(array, pivot + 1, end);


}
/**
 * quick_sort - sort
 * @array: our array
 * @size: size of array
 *
 * Return: no rreturn
 */
void quick_sort(int *array, size_t size)
{
	int low = 0;
	int high;

	if (size == 0)
	{
		return;
	}

	high = size - 1;
	quick(array, low, high);
}
