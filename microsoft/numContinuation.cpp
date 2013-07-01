/*
 * 一个整数序列，元素可能是0 - 65535中的任意一个数，相同数值不会重复出现， 
 * 0是例外可以反复出现。设计一个算法，从中任取5个数，判断是否连续
 * 注意: 数值可以是乱序的，0可以通配任意数值
 * 
 * author:	dongbeibei
 * time:		2013/7/1
 */


#include <iostream>
#include <limits.h>

using namespace std;

int minValue(int *array, int len);
bool numContinue(int *array, int len);

int main(void)
{
	int array[] = {76,0,0,0,81};
	int len = sizeof(array)/sizeof(array[0]);

	cout<<"result:\t"<<numContinue(array, len)<<endl;

	return 0;
}

int minValue(int *array, int len)
{
	int min;

	min = INT_MAX;
	for(int i=0 ; i<len ; i++)
	{
		if(array[i] && array[i]<min)
			min = array[i];
	}

	return min;
}

bool numContinue(int *array, int len)
{
	int min;
	bool flag;

	min = minValue(array, len);
	flag = true;

	cout<<"min:"<<min<<endl;
	for(int i=0 ; i<len ; i++)
	{
		if(array[i] && array[i]-min>4)
			flag = false;
	}

	return flag;
}
