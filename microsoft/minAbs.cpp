/*
 * 有一个整数数组，请求出两两之差绝对值最小的值，
 * 只要得出最小值即可，不需要求出是哪两个数。
 *
 * author:	dongbeibei
 * time:		2013/6/28
 */


#include <iostream>
#include <stdlib.h>
#include <limits.h>

using namespace std;

int comp(const void *a, const void *b);
int minValue(int *array, int len);

int main(void)
{
	int test[] = {2, 99, 137, 44, 213, 175};
	int len = sizeof(test)/sizeof(int);
	int result;

	result = minValue(test, len);

	cout<<"result:\t"<<result<<endl;

	return 0;
}

int comp(const void *a, const void *b)
{
	return *(int*)a - *(int*)b;
}

int minValue(int *array, int len)
{
	int	min = INT_MAX;
	int temp;

	qsort(array, len, sizeof(int), comp);

	for(int i=1 ; i<len ; i++)
	{
		temp = array[i] - array[i-1];

		if(temp>0)
			if(min > temp)
				min = temp;
		else if(temp<0)
			if(min+temp>0)
				min = 0 - temp;
		else
		{
			min = 0;
			break;
		}
	}

	return min;
}
