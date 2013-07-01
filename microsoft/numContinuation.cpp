/*
 * һ���������У�Ԫ�ؿ�����0 - 65535�е�����һ��������ͬ��ֵ�����ظ����֣� 
 * 0��������Է������֡����һ���㷨��������ȡ5�������ж��Ƿ�����
 * ע��: ��ֵ����������ģ�0����ͨ��������ֵ
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
