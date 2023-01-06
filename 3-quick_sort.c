#include "sort.h"

/**
* lomuto - the partition scheme for the quicksort
*
* @arr: array to be sorted
* @low: lowest index of the array
* @high: highest index of the array
*
* Return: returns an index
*/

int lomuto(int *arr, int low, int high)
{
	int p, i, j, t;
	static int size, k;

	if (k == 0)
		size = high + 1, k++;
	p = arr[high];
	i = low;
	for (j = low; j < high; j++)
	{
		if (arr[j] <= p)
		{
			if (i != j)
			{
				t = arr[i];
				arr[i] = arr[j];
				arr[j] = t;
				print_array(arr, size);
			}
			i++;
		}
	}
	if (i != high)
	{
		t = arr[i];
		arr[i] = arr[high];
		arr[high] = t;
		print_array(arr, size);
	}

	return (i);
}

/**
* actualsort - Where the quicksort actually happens (utilizes recursion)
* @arr: array to be sorted sort
* @low: lowest index of arr
* @high: highest index of arr
*/

void actualsort(int *arr, int low, int high)
{
	int p;

	if (low < high)
	{
		p = lomuto(arr, low, high);
		actualsort(arr, low, p - 1);
		actualsort(arr, p + 1, high);
	}
}


/**
* quick_sort - sorts array using the quicksort algorithm
* under the Lomuto partition scheme
*
* @arr: Array to be sort
* @size: Size of arr
*/

void quick_sort(int *arr, size_t size)
{
	if (!arr)
		return;
	actualsort(arr, 0, size - 1);
}
