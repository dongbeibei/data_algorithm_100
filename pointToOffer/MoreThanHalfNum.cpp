/*
 * function: find the number which is more than half times in an array
 *
 * author:	dongbeibei
 * time:	2013/8/29
 */

#include <iostream>

using namespace std;

int flag = 0;

bool CheckMoreThanHalf(int array[], int length, int num)
{
	int times = 0;

	for(int i=0 ; i<length ; ++i)
		if(array[i] == num)
			++times;

	if(times * 2 <= length)
		return false;
	else
		return true;
}

int NumMoreThanHalf(int array[], int length)
{
	flag = 0;

	if(array==NULL || length<=0)
	{
		flag = 1;
		return 0;
	}

	int result = array[0];
	int times = 1;
	for(int i=1 ; i<length ; ++i)
	{
		if(times == 0)
		{
			result = array[i];
			times = 1;
		}
		else if(array[i] == result)
			++times;
		else
			--times;
	}

	if(!CheckMoreThanHalf(array, length, num))
	{
		flag = 2;
		result = 0;
	}

	return result;
}

//follow: Unit Test
//
void test1();
//
void test2();
//
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


}

void test2()
{
	cout<<"Test 2:\n";


}

void test3()
{
	cout<<"Test 3:\n";


}
