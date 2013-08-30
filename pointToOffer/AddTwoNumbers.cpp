/*
 * function: add two numbers, can not use + , - , * , /
 *
 * author:	dongbeibei
 * time:	2013/8/30
 */

#include <iostream>

using namespace std;

int Add(int num1, int num2)
{
	int sum, carry;

	do
	{
		sum = num1 ^ num2;
		carry = (num1 & num2)<<1;

		num1 = sum;
		num2 = carry;
	}while(num2 != 0);

	return num1;
}

//follow: Unit Test
//input: 正数，0,负数
void test();

int main(void)
{
	test();

	return 0;
}

void test()
{
	cout<<"1 + 2 = "<<Add(1, 2)<<endl;
	cout<<"-1 + -2 = "<<Add(-1, -2)<<endl;
	cout<<"1 + -2 = "<<Add(1, -2)<<endl;
	cout<<"-1 + 2 = "<<Add(-1, 2)<<endl;
	cout<<"1 + 0 = "<<Add(1, 0)<<endl;
	cout<<"-1 + 0 = "<<Add(-1, 0)<<endl;
	cout<<"75 + 74 = "<<Add(75, 74)<<endl;
	cout<<"-75 + -74 = "<<Add(-75, -74)<<endl;
}
