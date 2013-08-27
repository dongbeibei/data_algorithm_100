/*
 * function: find a num is in a rotated array or not
 *
 * author:	dongbeibei
 * time:	2013/8/27
 */

#include <iostream>
#include <exception>

using namespace std;

int helper(int *array, int start, int end)
{
	int result = array[start];
	for(int i=start+1 ; i<=end ; ++i)
		if(result > array[i])
			result = array[i];

	return result;
}

int Min(int *array, int len)
{
	if(array==NULL || len<=0)
		throw new exception();

	int index1 = 0;
	int index2 = len - 1;
	int indexMid = index1;
	while(array[index1] >= array[index2])
	{
		if(index1 == index2 - 1)
		{
			indexMid = index2;
			break;
		}

		indexMid = index1 + (index2 - index1)/2;
		if(array[index1]==array[index2] && array[index1]==array[indexMid])
			return helper(array, index1, index2);
		else if(array[index1] <= array[indexMid])
		{
			index1 = indexMid;
		}
		else if(array[index2] >= array[indexMid])
		{
			index2 = indexMid;
		}
	}

	return array[indexMid];
}

//follow: Unit Test
void test1();
void test2();
void test3();

int main()
{
	test1();
	test2();
	test3();

	return 0;
}

void test1()
{
	int array[] = {3,4,5,1,2};
	int len = 5;
	int result = Min(array, len);

	cout<<"Test 1:\n";
	cout<<"except result:\t"<<"1"<<endl;
	cout<<"real except:\t"<<result<<endl;
}

void test2()
{
	int array[] = {1,0,1,1,1};
	int len = 5;
	int result = Min(array, len);

	cout<<"Test 2:\n";
	cout<<"except result:\t"<<"0"<<endl;
	cout<<"real except:\t"<<result<<endl;
}

void test3()
{
	int *array = NULL;
	int len = 5;
	int result = Min(array, len);

	cout<<"Test 3:\n";
	cout<<"except result:"<<endl;
	cout<<"real except:"<<result<<endl;
}
