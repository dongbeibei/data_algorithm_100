#include <iostream>

using namespace std;

void sumofsub(int t, int k, int r, int &M, bool &flag, bool *X);
void search(int &N, int &M);

int main(void)
{
	int n, sum;
	cout<<"intput the sum: ";
	cin>>sum;
	cout<<"input n: ";
	cin>>n;
	cout<<"all results:\n";
	search(n, sum);

	return 0;
}

void sumofsub(int t, int k, int r, int &M, bool &flag, bool *X)
{
	X[k] = true;

	if(t + k == M)
	{
		flag = true;
		for(int i=1 ; i<k ; ++i)
		{
			if(X[i] == 1)
				cout<<i<<"+";
		}
		cout<<k<<endl;
	}
	else
	{
		if(t + k + (k+1) <= M)
		{
			sumofsub(t+k, k+1, r-k, M, flag, X);
		}
		if((t+r-k>=M) && (t+(k+1)<=M))
		{
			X[k] = false;
			sumofsub(t, k+1, r-k, M, flag, X);
		}
	}
}

void search(int &N, int &M)
{
	bool *X = new bool[N+1];
	for(int i=0 ; i<N+1 ; ++i)
		X[i] = false;

	int sum = (N+1) * N / 2;
	if(1>M || sum<M)
	{
		cout<<"no found\n";
		return;
	}

	bool f = false;
	sumofsub(0, 1, sum, M, f, X);
	if(!f)
	{
		cout<<"no found\n";
	}

	delete X;
}
