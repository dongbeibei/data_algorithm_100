/*
谷歌笔试：
n 支队伍比赛，分别编号为0，1，2。。。。n-1，已知它们之间的实力对比关系，
存储在一个二维数组w[n][n]中，w[i][j] 的值代表编号为i，j 的队伍中更强的一支。
所以w[i][j]=i 或者j，现在给出它们的出场顺序，并存储在数组order[n]中，
比如order[n] = {4,3,5,8,1......}，那么第一轮比赛就是4 对3， 5 对8。.......
胜者晋级，败者淘汰，同一轮淘汰的所有队伍排名不再细分，即可以随便排，
下一轮由上一轮的胜者按照顺序，再依次两两比，比如可能是4 对5,直至出现第一名
编程实现，给出二维数组w，一维数组order 和用于输出比赛名次的数组result[n]，
求出result。
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
