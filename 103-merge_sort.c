#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
* merge - merges two subarrays into one sorted array
* @array: original array
* @temp: temporary array for merging
* @left: starting index of left subarray
* @mid: ending index of left subarray
* @right: ending index of right subarray
*/
void merge(int *array, int *temp, size_t left, size_t mid, size_t right)
{
size_t i = left, j = mid, k = left;

printf("Merging...\n[left]: ");
print_array(array + left, mid - left);
printf("[right]: ");
print_array(array + mid, right - mid);

while (i < mid && j < right)
{
if (array[i] <= array[j])
temp[k++] = array[i++];
else
temp[k++] = array[j++];
}
while (i < mid)
temp[k++] = array[i++];
while (j < right)
temp[k++] = array[j++];

for (i = left; i < right; i++)
array[i] = temp[i];

printf("[Done]: ");
print_array(array + left, right - left);
}

/**
* merge_sort_recursion - recursive helper for merge sort
* @array: array to sort
* @temp: temp array
* @left: start index
* @right: end index
*/
void merge_sort_recursion(int *array, int *temp, size_t left, size_t right)
{
size_t mid;

if (right - left < 2)
return;

mid = (left + right) / 2;
merge_sort_recursion(array, temp, left, mid);
merge_sort_recursion(array, temp, mid, right);
merge(array, temp, left, mid, right);
}

/**
* merge_sort - sorts an array of integers using Merge sort
* @array: array to sort
* @size: size of the array
*/
void merge_sort(int *array, size_t size)
{
int *temp;

if (!array || size < 2)
return;

temp = malloc(sizeof(int) * size);
if (!temp)
return;

merge_sort_recursion(array, temp, 0, size);
free(temp);
}
