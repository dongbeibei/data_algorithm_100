/*
在一个int 数组里查找这样的数，它大于等于左侧所有数，小于等于右侧
所有数。直观想法是用两个数组a、b。a[i]、b[i]分别保存从前到i 的最大的
数和从后到i 的最小的数，一个解答：这需要两次遍历，然后再遍历一次
原数组，将所有data[i]>=a[i-1]&&data[i]& lt;=b[i]的data[i]找出即可。

给出这个解答后，面试官有要求只能用一个辅助数组，
且要求少遍历一次。
 *
 * author:	dongbeibei
 * time:		2013/6/28
 */


#include <iostream>
#include <limits.h>

using namespace std;

void findValue(int *array, int len);
void findValue_2(int *array, int len);

int main(void)
{
	int arr[] = {1, 2, 4, 5, 6, 7, 8, 9, 10, 3, 11};
	int len = sizeof(arr)/sizeof(int);

	findValue(arr, len);
	findValue_2(arr, len);

	return 0;
}

void findValue(int *array, int len)
{
	if(!array || len<=0)
	{
		cout<<"the array is empty!"<<endl;
		return;
	}

	int *max = new int[len];
	int *min = new int[len];
	int maxValue = INT_MIN;
	int minValue = INT_MAX;
	
	for(int i=0 ; i<len ; i++)
	{
		if(array[i] > maxValue)
			max[i] = array[i];
		else
			max[i] = maxValue;

		maxValue = max[i];
	}
/*
	cout<<"max array:\t";
	for(int i=0 ; i<len ; i++)
		cout<<max[i]<<"  ";
	cout<<endl;
*/
	for(int i=len-1 ; i>=0 ; i--)
	{
		if(array[i] < minValue)
		{
			min[i] = array[i];
			minValue = min[i];
		}
		else
			min[i] = minValue;
	}
/*
	cout<<"min array:\t";
	for(int i=0 ; i<len ; i++)
		cout<<min[i]<<"  ";
	cout<<endl;
*/

	cout<<"origin array:\t";
	for(int i=0 ; i<len ; i++)
		cout<<array[i]<<"  ";
	cout<<endl;
	
	cout<<"result:\t";
	for(int i=0 ; i<len ; i++)
		if(array[i]>=max[i] && array[i]<=min[i])
			cout<<array[i]<<"  ";
	cout<<endl;
}

void findValue_2(int *array, int len)
{
	if(!array || len<=0)
	{
		cout<<"the array is empty!"<<endl;
		return;
	}

	int *cand = new int[len];
	int index = 0;
	int max, i;
	
	cand[index++] = array[0];
	max = array[0];
	for(i=1 ; i<len ; i++)
	{
		if(array[i] >= max)
		{
			cand[index++] = array[i];
			max = array[i];
		}
		else
		{
			while(index>0 && cand[index-1]>array[i])
				index--;
		}
	}

	cout<<"origin array:\t";
	for(int i=0 ; i<len ; i++)
		cout<<array[i]<<"  ";
	cout<<endl;
	
	cout<<"result:\t";
	for(int i=0 ; i<index ; i++)
		cout<<cand[i]<<"  ";
	cout<<endl;
}
