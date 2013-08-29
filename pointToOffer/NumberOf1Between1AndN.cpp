/*
 * function: count the number of 1 between 1 and N
 *
 * author:	dongbeibei
 * time:	2013/8/29
 */

#include <iostream>

using namespace std;

int Power10(int length)
{
	int result = 1;

	for(int i=0 ; i<length ; ++i)
		result *= 10;

	return result;
}

int helper(const char *strN)
{
	if(!strN || *strN<'0' || *strN>'9' || *strN=='\0')
		return 0;

	int first = *strN - '0';
	int length = strlen(strN);

	if(length == 1)
	{
		if(first == 0)
			return 0;
		else
			return 1;
	}

	if(first > 1)
		numFirstDigit = Power10(length - 1);
	else if(first == 1)
		numFirstDigit = atoi(strN+1) + 1;

	int numOtherDigit = first * (length-1) * Power10(length - 2);
	int numLeft = helper(strN+1);

	return numFirstDigit + numOtherDigit + numLeft;
}

int NumOf1Between1AndN(int number)
{
	if(number <= 0)
		return 0;

	char strN[50];
	sprintf(strN, "%d", number);

	return helper(strN);
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
