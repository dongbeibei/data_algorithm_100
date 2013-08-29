/*
 * function: find the count number of inverse pairs in the array
 *
 * author:	dongbeibei
 * time:	2013/8/29
 */

#include <iostream>

using namespace std;

int helper(int *array, int *copy, int start, int end)
{
	if(start == end)
	{
		copy[start] = array[start];
		return 0;
	}

	int mid = start + (end - start)/2;
	int left = helper(copy, array, start, mid);
	int right = helper(copy, array, mid+1, end);

	int i = mid, j = end;
	int indexCopy = end;
	int count = 0;
	while(i>=start && j>=mid+1)
	{
		if(array[i] > array[j])
		{
			copy[indexCopy--] = array[i--];
			count += j - mid;
		}
		else
			copy[indexCopy--] = array[j--];
	}

	for( ; i>=start ; --i)
		copy[indexCopy--] = array[i];
	for( ; j>=mid+1 ; --j)
		copy[indexCopy--] = array[j];

	return left + right + count;
}

int InversePairs(int array[], int len)
{
	if(array==NULL || len<=0)
		return 0;

	int *copy = new int[len];
	for(int i=0 ; i<len ; ++i)
		copy[i] = array[i];

	int count = helper(array, copy, 0, len-1);
	delete []copy;
	return count;
}

//follow: Unit Test
//the corrent input: unorder, order increase, order decrease, repeating number
void test1();
//input one number or two numbers
void test2();
//input is NULL
void test3();

int main(void)
{
	test1();
	cout<<endl;
	test2();
	cout<<endl;
	test3();

	return 0;
}

void test1()
{
	cout<<"Test 1:\n";

	int array1[] = {5,2,4,1,3};
	int len = 5;
	cout<<"result:\t"<<InversePairs(array1, len)<<endl;

	int array2[] = {1,2,3,4,5};
	cout<<"result:\t"<<InversePairs(array2, len)<<endl;

	int array3[] = {5,4,3,2,1};
	cout<<"result:\t"<<InversePairs(array3, len)<<endl;

	int array4[] = {5,4,2,2,1};
	cout<<"result:\t"<<InversePairs(array4, len)<<endl;
}

void test2()
{
	cout<<"Test 2:\n";

	int array1[] = {5,2};
	int len = 2;
	cout<<"result:\t"<<InversePairs(array1, len)<<endl;

	int array2[] = {5};
	len = 1;
	cout<<"result:\t"<<InversePairs(array2, len)<<endl;
}

void test3()
{
	cout<<"Test 3:\n";

	int *array = NULL;
	int len = 3;
	cout<<"result:\t"<<InversePairs(array, len)<<endl;
}
