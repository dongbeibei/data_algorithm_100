/*
��N��������M�����ӣ��Ѽ����ŵ�M�������ÿ�����Ӷ�����Ϊ�ա�
���⣬��Ҫ���㣺����һ��С��N����������������ĳ���������ڵ�
��������ӵĺ͵õ���
д������ʹ������һ��(N,M)��������п��ܵķ��������

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
