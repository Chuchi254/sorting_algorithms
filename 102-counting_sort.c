#include "sort.h"
#include <stdio.h>

/**
 * find_max - Finds the maximum value in an array of integers
 * @array: The array to be searched
 * @size: The size of the array
 *
 * Return: The maximum value in the array
 */
int find_max(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * counting_sort - Sorts an array of integers in ascending order using the
 * Counting sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void counting_sort(int *array, size_t size)
{
	int *count, *output, max, j;
	size_t i;

	if (!array || size < 2)
		return;
	max = find_max(array, size);
	count = malloc((max + 1) * sizeof(int));
	if (!count)
		return;
	for (i = 0; i <= (size_t)max; i++)
		count[i] = 0;
	for (i = 0; i < size; i++)
		count[array[i]]++;
	for (i = 0; i <= (size_t)max; i++)
	{
		for (j = 0; j < count[i]; j++)
		{
			printf("%ld", i);
			if (i < (size_t)max || j < count[i] - 1)
				printf(", ");
		}
	}
	printf("\n");
	for (i = 1; i <= (size_t)max; i++)
		count[i] += count[i - 1];
	output = malloc(size * sizeof(int));
	if (!output)
	{
		free(count);
		return;
	}
	for (i = size; i > 0; i--)
	{
		output[count[array[i - 1]] - 1] = array[i - 1];
		count[array[i - 1]]--;
	}
	for (i = 0; i < size; i++)
		array[i] = output[i];
	free(count);
	free(output);
}
