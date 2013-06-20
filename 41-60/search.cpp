/*
һ����������һ���ݼ�������������λ�γɵģ�����{4��3��2��1��6��5}
����{6��5��4��3��2��1}������λ�γɵģ������������в���ĳһ������
 *
 * author:	dongbeibei
 * time:		2013/6/19
 */


#include <iostream>

using namespace std;

int BinSearch(int *a, int len, int key);
int helper(int *a, int start, int end, int key);

int main(void)
{
	int a[] = {4, 3, 2, 1, 6, 5};
	int len = sizeof(a)/sizeof(int);
	int key = 6;

	int space = BinSearch(a, len, key);
	cout<<"result:\t"<<space<<": "<<a[space]<<endl;

	return 0;
}

int BinSearch(int *a, int len, int key)
{
	helper(a, 0, len-1, key);
}

int helper(int *a, int start, int end, int key)
{
	if(start > end)
		return -1;
	
	int mid = start + (end - start)/2;

	if(key == a[mid])
		return mid;
	else if(key == a[start])
		return start;
	else if(key<a[start] && key>a[mid])
		helper(a, start, mid-1, key);
	else
		helper(a, mid+1, end, key);
}
