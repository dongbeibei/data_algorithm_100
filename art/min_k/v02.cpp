/*
 * 借助快速排序的方法实现
 */

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int kth_elem(int a[], int low, int high, int k);

int main(void)
{
	for(int num=5000 ; num<50000001 ; num*=10)
	{
		int *array = new int[num];

		int j = num/10;
		int acc = 0;
		for(int k=1 ; k<=num ; k+=j)
		{
			srand(unsigned(time(0)));
			for(int i=0 ; i<num ; ++i)
				array[i] = rand() * RAND_MAX + rand();

			clock_t start = clock();
			int data = kth_elem(array, 0, num-1 , k);
			clock_t end = clock();
			acc += (end - start);
		}

		cout<<"The average time of searching a date in the array size of "<<num<<" is "<<(float)acc/10/CLOCKS_PER_SEC<<endl;
	}

	return 0;
}

int kth_elem(int a[], int low, int high, int k)
{
	int pivot = a[low];
	int low_temp = low;
	int high_temp = high;

	while(low < high)
	{
		while(low<high && a[high]>=pivot)
			--high;
		a[low] = a[high];
		while(low<high && a[low]<pivot)
			++low;
		a[high] = a[low];
	}
	a[low] = pivot;

	if(low == k-1)
		return a[low];
	else if(low > k-1)
		return kth_elem(a, low_temp, low-1, k);
	else
		return kth_elem(a, low+1, high_temp, k);
}
