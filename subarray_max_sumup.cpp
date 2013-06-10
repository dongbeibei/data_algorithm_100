/*
 * the max sum up of the sub array
 * author: dongbeibei
 * building time: 2013/6/9
 * modifing time:
 */


#include <iostream>

using namespace std;

int maxsum(int *array, int n);

int main()
{
	int test1[] = {1, -2, 3, -2, 4, 7, -3, 8};
	int test2[] = {-2, -1, -3};

	cout<<maxsum(test1, sizeof(test1)/sizeof(int))<<endl;
	cout<<maxsum(test2, sizeof(test2)/sizeof(int))<<endl;

	return 0;
}

int maxsum(int *array, int n)
{
	int sum, b, i;

	sum = -65535;
	b = 0;
	for(i=0 ; i<n ; i++)
	{
		if(b < 0)
			b = array[i];
		else
			b += array[i];

		if(sum < b)
			sum = b;
	}

	return sum;
}
