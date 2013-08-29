/*
 * function: get the ugly number
 *
 * author:	dongbeibei
 * time:	2013/8/29
 */

#include <iostream>

using namespace std;

int Min(int i, int j, int k)
{
	int result = (i<j) ? i : j;

	result = (result<k) ? result : k;

	return result;
}

int GetUglyNumber(int index)
{
	if(index <= 0)
		return 0;

	int *pUglyNumber = new int[index];
	pUglyNumber[0] = 1;
	int *pMultiply2, *pMultiply3, *pMultiply5;

	pMultiply2 = pMultiply3 = pMultiply5 = pUglyNumber;

	for(int i=1 ; i<index ; ++i)
	{
		int flag;
		int min = Min(*pMultiply2 * 2, *pMultiply3 * 3, *pMultiply5 * 5);
		pUglyNumber[i] = min;

		while(*pMultiply2 * 2 <= min)
			++pMultiply2;
		while(*pMultiply3 * 3 <= min)
			++pMultiply3;
		while(*pMultiply5 * 5 <= min)
			++pMultiply5;
	}

	int ugly = pUglyNumber[index-1];
	delete []pUglyNumber;

	return ugly;
}

//follow: Unit Test
//input: 2, 3, 4, 5, 6
void test1();
//input: -1, 0, 1
void test2();
//input: 1500
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

	for(int i=2 ; i<100 ; ++i)
		cout<<"result "<<i<<": "<<GetUglyNumber(i)<<endl;
}

void test2()
{
	cout<<"Test 2:\n";

	for(int i=-1 ; i<2 ; ++i)
		cout<<"result "<<i<<": "<<GetUglyNumber(i)<<endl;
}

void test3()
{
	cout<<"Test 3:\n";

	cout<<"result 1500: "<<GetUglyNumber(1500)<<endl;
}
