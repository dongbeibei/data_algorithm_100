/*
��һ��int ������������������������ڵ��������������С�ڵ����Ҳ�
��������ֱ���뷨������������a��b��a[i]��b[i]�ֱ𱣴��ǰ��i ������
���ʹӺ�i ����С������һ���������Ҫ���α�����Ȼ���ٱ���һ��
ԭ���飬������data[i]>=a[i-1]&&data[i]& lt;=b[i]��data[i]�ҳ����ɡ�

��������������Թ���Ҫ��ֻ����һ���������飬
��Ҫ���ٱ���һ�Ρ�
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
