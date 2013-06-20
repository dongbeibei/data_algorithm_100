/*
�ȸ���ԣ�
n ֧����������ֱ���Ϊ0��1��2��������n-1����֪����֮���ʵ���Աȹ�ϵ��
�洢��һ����ά����w[n][n]�У�w[i][j] ��ֵ������Ϊi��j �Ķ����и�ǿ��һ֧��
����w[i][j]=i ����j�����ڸ������ǵĳ���˳�򣬲��洢������order[n]�У�
����order[n] = {4,3,5,8,1......}����ô��һ�ֱ�������4 ��3�� 5 ��8��.......
ʤ�߽�����������̭��ͬһ����̭�����ж�����������ϸ�֣�����������ţ�
��һ������һ�ֵ�ʤ�߰���˳�������������ȣ����������4 ��5,ֱ�����ֵ�һ��
���ʵ�֣�������ά����w��һά����order ����������������ε�����result[n]��
���result��
 *
 * author:	dongbeibei
 * time:		2013/6/17
 */


#include <iostream>
#include <queue>

using namespace std;

//method 1: use array result[] to store the result, read the matrix to swap the result element
void swap(int *result, int i, int j);
void race(int **w, int *order, int *result, int n);
//method 2: use Queue STL to store the result;
void make_queue(int **w, int *order, int *result, int n);

int main(void)
{
	int w[6][6] = {
		0,1,2,3,0,0,
		1,1,2,1,1,1,
		2,2,2,2,2,2,
		3,1,2,3,3,3,
		0,1,2,3,4,5,
		0,1,2,3,5,5};
	int order[6] = {1,3,4,2,0,5};
	int result[6] = {-1};
	int n = 6;

	//race((int**)w, order, result, n);
	make_queue((int**)w, order, result, n);

	cout<<"result:\n\t";
	for(int i=0 ; i<n ; i++)
		cout<<result[i]<<"  ";
	cout<<endl;

	return 0;
}

void swap(int *result, int i, int j)
{
	if(i == j)
		return;

	int temp;
	temp = result[i];
	result[i] = result[j];
	result[j] = temp;
}

void race(int **w, int *order, int *result, int n)
{
	int i, j ,len ,temp;

	for(i=0 ; i<n ; i++)
		result[i] = order[i];

	len = n;
	while(len > 1)
	{
		for(i=0,j=0 ; i<len ; i=i+2,j++)
		{
			if(i == len-1)
				temp = result[i];
			else
				temp = *((int*)w + result[i]*n + result[i+1]);

			if(temp == result[i])
				temp = i;
			else
				temp = i+1;
			
			swap(result, temp, j);
		}
		len /= 2;
	}
}

void make_queue(int **w, int *order, int *result, int n)
{
	queue<int>	winner;

	int i, j, first, second;

	for(i=0 ; i<n ; i++)
	{
		winner.push(order[i]);
	}

	j = n-1;
	while(!winner.empty())
	{
		first = winner.front();
		winner.pop();
		if(winner.empty())
		{
			result[j--] = first;
			break;
		}
		second = winner.front();
		winner.pop();

		if(first == *((int*)w + first*n + second))
		{
			winner.push(first);
			result[j--] = second;
		}
		else
		{
			winner.push(second);
			result[j--] = first;
		}
	}
}
