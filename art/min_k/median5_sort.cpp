#include <iostream>
#include <time.h>

using namespace std;

const int num_array = 13;
const int num_med_array = num_array / 5 + 1;
int array[num_array];
int median_array[num_med_array];

void insert_sort(int array[], int left, int loop_times);
int find_median(int array[], int left, int right);
int find_index(int array[], int left, int right, int median);
int q_select(int array[], int left, int right, int k);

int main(void)
{
	int array[num_array] = {0,45,78,55,47,4,1,2,7,8,96,36,45};

	int k = 4;
	int i = q_select(array, 0, num_array-1, k);
	cout<<i<<endl;

	return 0;
}

void insert_sort(int array[], int left, int loop_times)
{
	for(int j=left ; j<left+loop_times ; ++j)
	{
		int key = array[j];
		int i = j - 1;
		while(i>left && array[i]>key)
		{
			array[i+1] = array[i];
			--i;
		}
		array[i+1] = key;
	}
}

int find_median(int array[], int left, int right)
{
	if(left == right)
		return array[left];

	int index;
	for(index=left ; index<right-5 ; index+=5)
	{
		insert_sort(array, index, 4);
		int num = index - left;
		median_array[num/5] = array[index+2];
	}

	int remain_num = right - index + 1;
	if(remain_num > 0)
	{
		insert_sort(array, index, remain_num-1);
		int num = index - left;
		median_array[num/5] = array[index+remain_num/2];
	}

	int elem_aux_array = (right - left)/5 - 1;
	if((right - left)%5 != 0)
		++elem_aux_array;

	if(elem_aux_array == 0)
		return median_array[0];
	else
		return find_median(median_array, 0, elem_aux_array);
}

int find_index(int array[], int left, int right, int median)
{
	for(int i=left ; i<=right ; ++i)
	{
		if(array[i] == median)
			return i;
	}

	return -1;
}

int q_select(int array[], int left, int right, int k)
{
	int median = find_median(array, left, right);

	int index = find_index(array, left, right, median);
	swap(array[index], array[right]);

	int pivot = array[right];
	int i = left;
	int j = right - 1;

	while(true)
	{
		while(array[i] < pivot)
			++i;
		while(array[j] > pivot)
			--j;
		if(i < j)
			swap(array[i], array[j]);
		else
			break;
	}
	swap(array[i], array[right]);

	int m = i - left + 1;
	if(m == k)
		return array[i];
	else if(m > k)
		return q_select(array, left, i - 1, k);
	else
		return q_select(array, i+1 , right, k-m);
}
