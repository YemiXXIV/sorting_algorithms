#include "sort.h"

/**
 * quick_sort - sorts an array of integers in ascending order using
 * the Quick sort algorithm with Lomuto partition scheme
 * @array: array to sort
 * @size: size of the array
 */

void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;

	quicksort_recursive(array, 0, size - 1, size);
}

/**
 * quicksort_recursive - recursive function to perform quicksort
 * @array: array to sort
 * @low: lowest index of the partition
 * @high: highest index of the partition
 * @size: size of the array
 */

void quicksort_recursive(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pi = lomuto_partition(array, low, high, size);

		quicksort_recursive(array, low, pi - 1, size);
		quicksort_recursive(array, pi + 1, high, size);
	}
}

/**
 * lomuto_partition - function to partition the array using Lomuto scheme
 * @array: array to partition
 * @low: lowest index of the partition
 * @high: highest index of the partition
 * @size: size of the array
 *
 * Return: index of the pivot element
 */

int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1, j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (array[high] < array[i + 1])
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * swap - swaps two integers in an array
 * @a: first integer
 * @b: second integer
 */

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
