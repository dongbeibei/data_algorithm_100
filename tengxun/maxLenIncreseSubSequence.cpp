/*
求最长递增子序列
 *
 * author:	dongbeibei
 * time:		2013/7/4
 */


#include <iostream>

using namespace std;

int maxSub(int *array, int *&result, int len);

int main(void)
{
	int array[] = {1,2,3,4,7,9,5,6,8};
	int len = sizeof(array)/sizeof(array[0]);
	int *result;
	int result_len;

	result_len = maxSub(array, result, len);
	cout<<"the max length:\t"<<result_len<<endl;
	cout<<"result:\n\t";
	for(int i=0 ; i<result_len ; i++)
		cout<<result[i]<<"  ";
	cout<<endl;

	delete []result;

	return 0;
}

int maxSub(int *array, int *&result, int len)
{
	if(!array || len<=0)
		return -1;

	int i, j;
	int *temp, *next;
	int max, max_temp;

	temp = new int[len];
	next = new int[len];
	temp[len-1] = 1;
	next[len-1] = -1;
	for(i=len-2 ; i>=0 ; i--)
	{
		max = 1;
		for(j=i+1 ; j<len ; j++)
		{
			if(array[j] > array[i])
			{
				if(max < temp[j]+1)
				{
					max = temp[j] + 1;
					max_temp = j;
				}
			}
		}

		if(max == 1)
		{
			temp[i] = 1;
			next[i] = -1;
		}
		else
		{
			temp[i] = max;
			next[i] = max_temp;
		}
	}
/*
	cout<<"temp:\t";
	for(i=0 ; i<len ; i++)
		cout<<temp[i]<<"  ";
	cout<<endl;

	cout<<"next:\t";
	for(i=0 ; i<len ; i++)
		cout<<next[i]<<"  ";
	cout<<endl;
*/
	max = 0;
	max_temp = 0;
	for(i=0 ; i<len ; i++)
	{
		if(temp[i] > max)
		{
			max = temp[i];
			max_temp = i;
		}
	}

	int result_len = 0;
	for(i=max_temp ; i!=-1 ; i=next[i])
	{
		result_len++;
	}
	result = new int[result_len];
	for(i=max_temp,j=0 ; i!=-1 ; i=next[i])
	{
		result[j++] = array[i];
	}

	return max;
}
