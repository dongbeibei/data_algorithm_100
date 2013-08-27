/*
 * function: print 1 to number of N digits
 *
 * author:	dongbeibei
 * time:	2013/8/27
 */

#include <iostream>

using namespace std;

bool Increment(char *str, int len)
{
	bool isOverflow = false;
	int nTakeOver = 0;

	for(int i=len-1 ; i>=0 ; --i)
	{
		int sum = str[i] - '0' + nTakeOver;

		if(i == len-1)
			++sum;

		if(sum >= 10)
		{
			if(i==0)
			{
				isOverflow = true;
				break;
			}
			else
			{
				sum -= 10;
				nTakeOver = 1;
				str[i] = '0' + sum;
			}
		}
		else
		{
			str[i] = sum + '0';
			break;
		}
	}

	return isOverflow;
}

void Print(char *str, int len)
{
	bool isBeginning0 = true;

	for(int i=0 ; i<len ; ++i)
	{
		if(isBeginning0 && str[i]!='0')
				isBeginning0 = false;

		if(!isBeginning0)
			cout<<str[i]-'0';
	}
	cout<<endl;
}

void Print1ToNumOfNDigits(int n)
{
	if(n <= 0)
		return;

	char *str = new char[n+1];
	for(int i=0 ; i<n ; ++i)
		str[i] = '0';
	str[n] = '\0';

	while(!Increment(str, n))
	{
		Print(str, n);
	}

	delete []str;
}

//follow: Unit Test
void test1();
void test2();

int main()
{
	test1();
	cout<<endl;
	test2();

	return 0;
}

void test1()
{
	int n = 5;

	cout<<"Test 1:\n";
	Print1ToNumOfNDigits(n);
}

void test2()
{
	int n = 0;

	cout<<"Test 2:\n";
	Print1ToNumOfNDigits(n);
}
