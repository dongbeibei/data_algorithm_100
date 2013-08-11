#include <iostream>
#include <cstdlib>

using namespace std;

inline int my_rand(int low, int high);
int partition(int array[], int left, int right);
bool median_select(int array[], int left, int right, int k);
bool rand_select(int array[], int left, int right, int k);
bool kth_element(int array[], int left, int right, int k);

int main(void)
{
	int array1[] = {7, 8, 9, 54, 6, 4, 11, 1, 2, 33};
	int array2[] = {7, 8, 9, 54, 6, 4, 11, 1, 2, 33};
	int array3[] = {7, 8, 9, 54, 6, 4, 11, 1, 2, 33};

	int numOfArray = sizeof(array1)/sizeof(int);
	cout<<"origin:";
	for(int i=0 ; i<numOfArray ; ++i)
		cout<<array1[i]<<"\t";
	cout<<endl;

	int k = 9;
	bool flag1 = median_select(array1, 0, numOfArray-1, k);
	bool flag2 = rand_select(array2, 0, numOfArray-1, k);
	bool flag3 = kth_element(array3, 0, numOfArray-1, k);

	if(!flag1)
		return 1;
	cout<<"result1:";
	for(int i=0 ; i<k ; ++i)
		cout<<array1[i]<<"\t";
	cout<<endl;
	
	if(!flag2)
		return 1;
	cout<<"result2:";
	for(int i=0 ; i<k ; ++i)
		cout<<array2[i]<<"\t";
	cout<<endl;

	if(!flag3)
		return 1;
	cout<<"result3:";
	for(int i=0 ; i<k ; ++i)
		cout<<array3[i]<<"\t";
	cout<<endl;

	return 0;
}

inline int my_rand(int low, int high)
{
	int size = high - low + 1;
	return low + rand()%size;
}

int partition(int array[], int left, int right)
{
	int pivot = array[right];
	int pos = left - 1;

	for(int index=left ; index<right ; ++index)
	{
		if(array[index] <= pivot)
			swap(array[++pos], array[index]);
	}
	swap(array[++pos], array[right]);

	return pos;
}

bool median_select(int array[], int left, int right, int k)
{
	if(k-1 > right || k-1 < left)
		return false;

	int midIndex = (left + right) / 2;
	if(array[left] < array[midIndex])
		swap(array[left], array[midIndex]);
	if(array[right] < array[midIndex])
		swap(array[right], array[midIndex]);
	if(array[right] < array[left])
		swap(array[right], array[left]);
	swap(array[midIndex], array[right]);

	int pos = partition(array, left, right);

	if(pos == k-1)
		return true;
	else if(pos > k-1)
		return median_select(array, left, pos-1, k);
	else
		return median_select(array, pos+1, right, k);
}

bool rand_select(int array[], int left, int right, int k)
{
	if(k-1 > right || k-1 < left)
		return false;

	int Index = my_rand(left, right);
	swap(array[Index], array[right]);

	int pos = partition(array, left, right);

	if(pos == k-1)
		return true;
	else if(pos > k-1)
		return rand_select(array, left, pos-1, k);
	else
		return rand_select(array, pos+1, right, k);
}

bool kth_element(int array[], int left, int right, int k)
{
	if(k-1 > right || k-1 < left)
		return false;

	int pos = partition(array, left, right);
	if(pos == k-1)
		return true;
	else if(pos > k-1)
		return kth_element(array, left, pos-1, k);
	else
		return kth_element(array, pos+1, right, k);
}
