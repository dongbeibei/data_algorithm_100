/*
求2个或N个数的最大公约数和最小公倍数
 *
 * author:	dongbeibei
 * time:		2013/7/2
*/


#include <iostream>

using namespace std;

int minValue(int *array, int len);
int min(int a, int b);
int maxValue(int *array, int len);
int max(int a, int b);

int main(void)
{
	int array[] = {2,3,4};
	int len = sizeof(array)/sizeof(array[0]);

	cout<<"max:\t"<<maxValue(array, len)<<endl;
	cout<<"min:\t"<<minValue(array, len)<<endl;

	return 0;
}

int minValue(int *array, int len)
{
	if(!array || len<=1)
		return -1;

	int result;

	for(int i=1 ; i<len ; i++)
	{
		if(i==1)
			result = min(array[0], array[1]);
		else
			result = min(result, array[i]);
	}

	return result;
}

int min(int a, int b)
{
	return a*b/max(a,b);
}
	
int maxValue(int *array, int len)
{
	if(!array || len<=1)
		return -1;

	int result;

	for(int i=1 ; i<len ; i++)
	{
		if(i==1)
			result = max(array[0], array[1]);
		else
			result = max(result, array[i]);
	}

	return result;

}

int max(int a, int b)
{
	int temp;

	if(a < b)
	{
		a = a^b;
		b = a^b;
		a = a^b;
	}
	while(b != 0)
	{
		temp = a%b;
		a = b;
		b = temp;
	}

	return a;
}
