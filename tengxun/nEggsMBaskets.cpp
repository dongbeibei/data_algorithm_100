/*
有N个鸡蛋和M个篮子，把鸡蛋放到M个篮子里，每个篮子都不能为空。
另外，需要满足：任意一个小于N的正整数，都能由某几个篮子内蛋
的数量相加的和得到。
写出程序，使得输入一个(N,M)，输出所有可能的分配情况。

 * 
*/

#include <iostream>

using namespace std;

long pow2[20];
int N,M;
int ans[1000];

void solve(int n, int m, int min);

int main(void)
{
	pow2[0] = 1;
	for(int i=1 ; i<20 ; i++)
		pow2[i] = pow2[i-1]<<1;

	cin>>N>>M;
	if(M>N || pow2[M]-1<N)
		cout<<"the result isn't exists."<<endl;

	solve(0, 0, 1);

	return 0;
}

void solve(int n, int m, int min)
{
	if(n==N && m==M)
	{
		for(int i=1 ; i<=M ; i++)
			cout<<ans[i]<<"  ";
		cout<<endl;
		return;
	}
	else if(n+(M-m)*min>N || N>pow2[M-m]*n+pow2[M-m]-1)
		return;
	else
	{
		for(int i=min ; i<=n+1 ; i++)
		{
			ans[m+1] = i;
			solve(n+i, m+1, i);
		}
	}
}
