/*
 * function: count the number K in the given sorted array
 *
 * author:	dongbeibei
 * time:	2013/8/29
 */

#include <iostream>

using namespace std;

int GetFirstK(int *array, int length, int key, int start, int end)
{
	if(start > end)
		return -1;

	int midIndex = start + (end - start)/2;
	int midKey = array[midIndex];

	if(midKey == key)
	{
		if(midIndex>0 && array[midIndex-1]!=key || midIndex==0)
			return midIndex;
		else
			end = midIndex - 1;
	}
	else if(midKey > key)
		end = midIndex - 1;
	else
		start = midIndex + 1;

	return GetFirstK(array, length, key, start, end);
}

int GetLastK(int *array, int length, int key, int start, int end)
{
	if(start > end)
		return -1;

	int midIndex = start + (end - start)/2;
	int midKey = array[midIndex];

	if(midKey == key)
	{
		if(midIndex<length-1 && array[midIndex+1]!=key || midIndex==length-1)
			return midIndex;
		else
			start = midIndex + 1;
	}
	else if(midKey > key)
		end = midIndex - 1;
	else
		start = midIndex + 1;

	return GetLastK(array, length, key, start, end);
}

int GetNumberOfK(int *array, int length, int key)
{
	int number = 0;

	if(array!=NULL && length>0)
	{
		int first = GetFirstK(array, length, key, 0, length-1);
		int last = GetLastK(array, length, key, 0, length-1);

		if(first>-1 && last>-1)
			number = last - first + 1;
	}

	return number;
}

//follow: Unit Test
//test output
void Test(char *name, int *data, int length, int exceptResult);
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

void Test(const char *name, int *data, int length, int key, int exceptResult)
{
	if(name!=NULL)
		cout<<name<<": ";

	if(GetNumberOfK(data, length, key) == exceptResult)
		cout<<"Passed."<<endl;
	else
		cout<<"Failed."<<endl;
}

void test1()
{
	int array[] = {1,2,3,3,5,5,5,6};
	int len = 8;

	Test("Test 1", array, len, 2, 1);
	Test("Test 2", array, len, 3, 2);
	Test("Test 3", array, len, 5, 3);
	Test("Test 4", array, len, 4, 0);
}

void test2()
{
	int array[] = {1,2,3,3,5,5,5,6};
	int len = 8;

	Test("Test 5", array, len, 1, 1);
	Test("Test 6", array, len, 6, 1);
}

void test3()
{
	int array1[] = {1};
	int len1 = 1;

	Test("Test 7", array1, len1, 1, 1);

	int *array2 = NULL;
	int len2 = 0;

	Test("Test 8", array2, len2, 1, 0);
}
