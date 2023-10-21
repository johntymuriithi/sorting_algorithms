#include "sort.h"

/**
 * swap - sort function
 * @a: first integer
 * @b: second integer
 *
 * Return: no return
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
/**
 * selection_sort - sort fucntion
 * @array: the array
 * @size: size of the array
 *
 * Return: no return
 */
void selection_sort(int *array, size_t size)
{
	size_t min_idx, i, j;

	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_idx])
			{
				min_idx = j;
			}
		}
		if (min_idx != i)
		{
			swap(&array[i], &array[min_idx]);
			print_array(array, size);
		}
	}
}
