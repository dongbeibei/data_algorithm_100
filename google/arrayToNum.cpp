/*
给定一个集合A = [0,1,3,8]（该集合中的元素都是在0,9之间的数字，
但未必全部包含），制定任意一个正整数K，请用A中的元素组成
一个大于K的最小正整数。

比如，A = [1,0] K=21 那么输出结构应该为100。
 *
 *
 * author:	dongbeibei
 * time:		2013/7/1
 */


#include <iostream>

using namespace std;

int numBits(int num, int *&num_array);
void myswap(int *a, int *b);
void sort(int *array, int len);
int numPack(int *array, int len, int num);

int main(void)
{
	int array[] = {1,0,8};
	int key = 1898;
	int len = sizeof(array)/sizeof(array[0]);

	cout<<"result:\t"<<numPack(array, len, key)<<endl;

	return 0;
}

int numBits(int num, int *&num_array)
{
	int i, temp;

	i = 1;
	temp = num;
	while(temp/10 != 0)
	{
		i++;
		temp /= 10;
	}

	num_array = new int[i];
	for(int j=i ; j>0 ; j--)
	{
		num_array[j-1] = num%10;
		num /= 10;
	}

	return i;
}

void myswap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void sort(int *array, int len)
{
	for(int i=0 ; i<len ; i++)
	{
		for(int j=0 ; j<len-i-1 ; i++)
		{
			if(array[j] > array[j+1])
				myswap(&array[j], &array[j+1]);
		}
	}
}

int numPack(int *array, int len, int num)
{
	if(!array || len<=0 || num<0)
	{
		cout<<"the input is error."<<endl;
		return -1;
	}

	int bits, result, temp, max, flag;
	int *num_array, *result_array;

	bits = numBits(num, num_array);
	result = flag = 0;
	sort(array, len);
	max = array[len-1];
	result_array = new int[bits];

	for(int i=0 ; i<bits ; i++)
	{
		int j;
		for(j=0 ; j<len && array[j]<num_array[i] ; j++);
		if(i==0 && j==len)
		{
			flag = 1;
			break;
		}
		else if(j==len)
		{
			flag = 2;
			temp = i;
			break;
		}
		else
		{
			result_array[i] = array[j];
		}
	}

	result = 0;
	if(flag == 1)
	{
		int i;
		for(i=0 ; i<len ; i++)
			if(array[i])
				break;
		result = array[i];
		for(i=0 ; i<bits ; i++)
			result = result * 10 + array[0];
	}
	else if(flag == 2)
	{
		int i, j;
		i = temp - 1;
		while(result_array[i] == max)
			i--;
		if(i < 0)
		{
			int i;
			for(i=0 ; i<len ; i++)
				if(array[i])
					break;
			result = array[i];
			for(i=0 ; i<bits ; i++)
				result = result * 10 + array[0];
		}
		else
		{
			for(j=0 ; j<i ; j++)
				result = result * 10 + result_array[j];
			int k;
			for(k=0 ; array[k]<=result_array[j] ; k++);
			result = result * 10 + array[k];
			j++;
			for( ; j<bits ; j++)
				result = result * 10 + array[0];
		}
	}
	else
	{
		int i, j;
		i = bits - 1;
		while(result_array[i] == max)
			i--;
		if(i < 0)
		{
			int i;
			for(i=0 ; i<len ; i++)
				if(array[i])
					break;
			result = array[i];
			for(i=0 ; i<bits ; i++)
				result = result * 10 + array[0];
		}
		else
		{
			for(j=0 ; j<i ; j++)
				result = result * 10 + result_array[j];
			int k;
			for(k=0 ; array[k]<=result_array[j] ; k++);
				//if(!array[k])
					//continue;
			result = result * 10 + array[k];
			j++;
			for( ; j<bits ; j++)
				result = result * 10 + array[0];
		}
	}

	return result;
}