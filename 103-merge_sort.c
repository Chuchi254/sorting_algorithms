#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * merge - Merges two subarrays of array[]
 * @array: The array to be sorted
 * @left: The starting index of the left subarray
 * @mid: The ending index of the left subarray and the starting index
 * of the right subarray
 * @right: The ending index of the right subarray
 * @temp: Temporary array for merging
 */
void merge(int *array, size_t left, size_t mid, size_t right, int *temp)
{
	size_t i, j, k, l, r, d;

	i = left;
	j = mid;
	k = left;

	printf("Merging...\n");
	printf("[left]: ");
	for (l = left; l < mid; l++)
		printf("%d%s", array[l], l < mid - 1 ? ", " : "");
	printf("\n[right]: ");
	for (r = mid; r < right; r++)
		printf("%d%s", array[r], r < right - 1 ? ", " : "");
	printf("\n");

	while (i < mid && j < right)
	{
		if (array[i] <= array[j])
			temp[k++] = array[i++];
		else
			temp[k++] = array[j++];
	}
	while (i < mid)
		temp[k++] = array[j++];
	for (i = left; i < right; i++)
		array[i] = temp[i];
	printf("[Done]: ");
	for (d = left; d < right; d++)
		printf("%d%s", array[d], d < right - 1 ? ", " : "");
	printf("\n");
}

/**
 * merge_sort_rec - Recursively sorts an array of integers using the Merge
 * sort algorithm
 * @array: The array to be sorted
 * @left: The starting index of the subarray
 * @right: The ending index of the subarray
 * @temp: Temporary array for merging
 */
void merge_sort_rec(int *array, size_t left, size_t right, int *temp)
{
	size_t mid;

	if (right - left > 1)
	{
		mid = left + (right - left) / 2;
		merge_sort_rec(array, left, mid, temp);
		merge_sort_rec(array, mid, right, temp);
		merge(array, left, mid, right, temp);
	}
}

/**
 * merge_sort - Sorts an array of integers in ascending order using the
 * Merge sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (!array || size < 2)
		return;

	temp = malloc(size * sizeof(int));
	if (!temp)
		return;

	merge_sort_rec(array, 0, size, temp);
	free(temp);
}
