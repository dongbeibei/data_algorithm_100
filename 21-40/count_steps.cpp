/*
��Ŀ��һ��̨���ܹ���n �������һ�ο�����1 ����Ҳ������2 ����
���ܹ��ж������������������㷨��ʱ�临�Ӷȡ�
���������������֣�����MicroStrategy �ȱȽ������㷨�Ĺ�˾
�����Ⱥ�ѡ�ù����������Ϊ��������߱����⡣
 *
 * author:	dongbeibei
 * time:		2013/6/12
 *
 * another method: a[n] record the result, in a oridinary way(from 1 to n)
 */


#include <iostream>

using namespace std;

int fib(int n);

int main(void)
{
	int		n;

	cout<<"input the total steps:\t";
	cin>>n;

	cout<<"the total methods:\t"<<fib(n)<<endl;

	return 0;
}

int fib(int n)
{
	if(n == 1)
		return 1;
	else if(n == 2)
		return 2;
	else
		return fib(n-1)+fib(n-2);
}
