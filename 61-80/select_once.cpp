/*
�ҳ�����������ֻ����һ�ε�����
��Ŀ��һ�����������������������֮�⣬���������ֶ����������Ρ�
��д�����ҳ�������ֻ����һ�ε����֡�Ҫ��ʱ�临�Ӷ���O(n)��
�ռ临�Ӷ���O(1)��

����������һ������ӱ�Ĺ���λ����������⡣

 *
 * author:	dongbeibei
 * time:		2013/6/20
 *
 * һ��ֻ����һ�ε�����ʱ��ֻ��Ҫ����һ�ε�������㣬
 *����ʱ��û���뵽��������ʵ�������ս������һ���µ���Ϣ��
 * �����Խ�ԭ���������Ϊ���࣬��������ͬ�����ֱַ��������ࡣ
 */


#include <iostream>

using namespace std;

void select_once_number(int *a, int len, int &num1, int &num2);
int isbit(int n, int num);

int main(void)
{
	int a[] = {1, 2, 3, 3, 4, 4};
	int len = sizeof(a)/sizeof(int);
	int num1, num2;

	num1 = num2 = 0;
	select_once_number(a, len, num1, num2);

	cout<<"num1:\t"<<num1<<endl;
	cout<<"num2:\t"<<num2<<endl;

	return 0;
}

void select_once_number(int *a, int len, int &num1, int &num2)
{
	int sum, first_non_zero;

	sum = 0;
	for(int i=0 ; i<len ; i++)
		sum ^= a[i];

	first_non_zero = 0;
	while((sum & 1)==0)
	{
		first_non_zero++;
		sum = sum>>1;
	}

	for(int i=0 ; i<len ; i++)
	{
		if(isbit(first_non_zero, a[i]))
			num1 ^= a[i];
		else
			num2 ^= a[i];
	}
}

int isbit(int n, int num)
{
	num = num>>n;

	return (num & 1);
}
