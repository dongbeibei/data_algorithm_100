/*
找出数组中两个只出现一次的数字
题目：一个整型数组里除了两个数字之外，其他的数字都出现了两次。
请写程序找出这两个只出现一次的数字。要求时间复杂度是O(n)，
空间复杂度是O(1)。

分析：这是一道很新颖的关于位运算的面试题。

 *
 * author:	dongbeibei
 * time:		2013/6/20
 *
 * 一个只出现一次的数字时，只需要进行一次的异或运算，
 *两个时，没有想到方法，其实异或的最终结果即是一个新的信息，
 * 它可以将原来的数组分为两类，而两个不同的数字分别属于两类。
 */


#include <iostream>

using namespace std;

void select_once_number(int *a, int len, int &num1, int &num2);
int isbit(int n, int num);

int main(void)
{
	int a[] = {1, 2, 3, 3, 4, 4};
	int len = sizeof(a)/sizeof(int);
	int num1, num2;

	num1 = num2 = 0;
	select_once_number(a, len, num1, num2);

	cout<<"num1:\t"<<num1<<endl;
	cout<<"num2:\t"<<num2<<endl;

	return 0;
}

void select_once_number(int *a, int len, int &num1, int &num2)
{
	int sum, first_non_zero;

	sum = 0;
	for(int i=0 ; i<len ; i++)
		sum ^= a[i];

	first_non_zero = 0;
	while((sum & 1)==0)
	{
		first_non_zero++;
		sum = sum>>1;
	}

	for(int i=0 ; i<len ; i++)
	{
		if(isbit(first_non_zero, a[i]))
			num1 ^= a[i];
		else
			num2 ^= a[i];
	}
}

int isbit(int n, int num)
{
	num = num>>n;

	return (num & 1);
}
