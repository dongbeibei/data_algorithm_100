/*
 * һ����n ��Ԫ�ص������������ٴ���һ���ظ�����Ԫ�ؾ�����[0, n-1]
 * ����ʵ�֣���O(n)ʱ�����ҳ���һ�ظ�����
 *
 * author:	dongbeibei
 * time:		2013/7/4
 */


#include <iostream>

using namespace std;

int findDoubleNum(int *array, int len);

int main(void)
{
	int array[] = {6,2,1,5,8,7,6,4,8};
	int len = sizeof(array)/sizeof(array[0]);

	cout<<"result:\t"<<findDoubleNum(array, len)<<endl;

	return 0;
}

int findDoubleNum(int *array, int len)
{
	int x, y;

	x = y = len;
	do
	{
		x = array[array[x-1]-1];
		y = array[y-1];
	}while(x != y);

	x = len;
	do
	{
		x = array[x-1];
		y = array[y-1];
	}while(x != y);

	return x;
}
