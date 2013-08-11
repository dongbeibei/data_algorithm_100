/*
 * 
 */


#include <iostream>

using namespace std;

int median3(int array[], int left, int right);
void qsort(int array[], int left, int right);

int median3(int array[], int left, int right)
{
	int mid = left + (right - left)/2;

	if(array[left] > array[mid])
		swap(&array[left], &array[mid]);
	if(array[left] > array[right])
		swap(&array[left], &array[right]);
	if(array[mid] > array[right])
		swap(&array[mid], &array[right]);

	swap(&array[mid], &array[right-1]);

	return array[right-1];
}

void qsort(int array[], int left, int right)
{
	int i, j;
	int pivot;

	if(left <= right)
	{
		pivot = median3(array left, right);
		i = left;
		j = right-1;
		for( ; ; )
		{
			while(array[++i] < pivot);
			while(array[--j] > pivot);
			if(i < j)
				swap(&array[i], &array[j]);
			else
				break;
		}
		swap(&array[i], &array[right-1]);
		qsort(array, left, i-1);
		qsort(array, i+1, right);
	}
}
