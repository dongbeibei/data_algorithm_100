/*
正整数序列 正整数序列 正整数序列 Q中的每个元素都至少能被
正整数 a和 b中的一个整除，现给定 a和 b， 需要计算出 Q中的前几项，
例如当 a=3，b=5，N=6时，序列为 3，5，6，9，10 ，12

(1)、设计一个函数 void generate（int a,int b,int N ,int *Q）计算 Q的前几项
(2)、设计测试数据来验证函数程序在各种输入下的正确性。
 *
 * author:	dongbeibei
 * time:		2013/7/1
 */
/*
 * 测试数据:
 *		a	b	N
 *		1	3	7
 *		3	1	7
 *		3	6	7
 *		6	3	7
 *		3	5	7
 *		5	3	7
 *
 *
 *		-1	4	7
 *		4	-1	7
 *		0	4	7
 *		4	0	7
 */

#include <iostream>

using namespace std;

void generate(int a, int b, int N, int *&Q);

int main(void)
{
	int a, b, N;
	int *Q;

	cout<<"input the first number:   ";
	cin>>a;
	cout<<"input the second number:  ";
	cin>>b;
	cout<<"input the generate N:     ";
	cin>>N;

	generate(a, b, N, Q);
	if(Q)
	{
		cout<<"the result:\n\t";
		for(int i=0 ; i<N ; i++)
			cout<<Q[i]<<"  ";
		cout<<endl;
	}

	return 0;
}

void generate(int a, int b, int N, int *&Q)
{
	if(a<1 || b<1 || N<1)
	{
		cout<<"ERROR: the input is invalid."<<endl;
		return;
	}

	Q = new int[N];
	if(!Q)
	{
		cout<<"ERROR: the new method."<<endl;
		return;
	}

	if(a==1 || b==1)
	{
		for(int i=0 ; i<N ; i++)
			Q[i] = i+1;
		return;
	}

	if(a > b)
	{
		int temp = a;
		a = b;
		b = temp;
	}

	if(b%a == 0)
	{
		for(int i=0 ; i<N ; i++)
			Q[i] = (i+1)*a;
		return;
	}

	int j, k;
	j = k = 1;
	for(int i=0 ; i<N ; i++)
	{
		if(j*a < k*b)
		{
			Q[i] = j*a;
			j++;
		}
		else if(j*a > k*b)
		{
			Q[i] = k*b;
			k++;
		}
		else
		{
			Q[i] = j*a;
			j++;
			k++;
		}
		cout<<Q[i]<<endl;
	}

	return;
}
