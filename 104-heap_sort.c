#include "sort.h"
#include <stdio.h>

/**
* heapify - ensures the heap property in a subtree
* @array: the array representing the heap
* @size: total size of the array
* @n: size of the heap part (decreasing each iteration)
* @i: current index (root of subtree)
*/
void heapify(int *array, size_t size, size_t n, size_t i)
{
size_t largest = i;
size_t left = 2 * i + 1;
size_t right = 2 * i + 2;
int temp;

if (left < n && array[left] > array[largest])
largest = left;

if (right < n && array[right] > array[largest])
largest = right;

if (largest != i)
{
temp = array[i];
array[i] = array[largest];
array[largest] = temp;
print_array(array, size);
heapify(array, size, n, largest);
}
}

/**
* heap_sort - sorts an array of integers using Heap sort algorithm
* @array: array to sort
* @size: size of the array
*/
void heap_sort(int *array, size_t size)
{
int temp;
ssize_t i;

if (!array || size < 2)
return;

/* Build max heap */
for (i = (size / 2) - 1; i >= 0; i--)
heapify(array, size, size, i);

/* Extract elements one by one from heap */
for (i = size - 1; i > 0; i--)
{
temp = array[0];
array[0] = array[i];
array[i] = temp;
print_array(array, size);
heapify(array, size, i, 0);
}
}
