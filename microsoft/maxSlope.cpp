/*
 * 平面上有N 个点，每两个点之间确定一条直线，
 * 求出斜率最大(斜率不存在的舍去)所通过的两个点
 *
 * author:	dongbeibei
 * time:		2013/7/1
 */


#include <iostream>

using namespace std;

void myswap(int &a, int &b);
void sort(int *x, int *y, int len);

int main(void)
{
	int x[]={1,6,4,2,3};
	int y[]={2,4,6,11,9};

	sort(x,y,5);
	double max=(y[1]-y[0])/(x[1]-x[0]);
	for(int i=2;i<5;i++)
	{
		double n = (y[i]-y[i-1])/(x[i]-x[i-1]);
		max = max>n?max:n;
	}
	cout<<"max = "<<max<<endl;  

	return 0;
}

void myswap(int &a, int &b)
{
	int temp;

	temp = a;
	a = b;
	b = temp;
}

void sort(int *x, int *y, int len)
{
	for(int i=0 ; i<len ; i++)
	{
		for(int j=0 ; j<len-i-1 ; j++)
		{
			if(x[j] > x[j+1])
			{
				myswap(x[j], x[j+1]);
				myswap(y[j], y[j+1]);
			}
		}
	}
}
