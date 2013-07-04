/*
题目：输入四个点的坐标，求证四个点是不是矩形
关键点：
1.相邻两边斜率之积等于-1，
2.矩形边与坐标系平行的情况下，斜率无穷大不能用积判断，
3.输入四点可能不按顺序排序，需要对四点排序。
 *
 * author:	dongbeibei
 * time:		2013/7/2
*/


#include <iostream>

using namespace std;

void myswap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

int main(void)
{
	//int x[] = {3,2,1,4};
	//int y[] = {-2,1,0,-1};
	int x[] = {1, 0, 0, 1};
	int y[] = {1, 1, 2, 2};
	int len = sizeof(x)/sizeof(x[0]);
	bool flag;

	for(int i=0 ; i<len ; i++)
	{
		for(int j=0 ; j<len-i-1 ; j++)
		{
			if(x[j]>x[j+1])
			{
				myswap(x[j], x[j+1]);
				myswap(y[j], y[j+1]);
			}
		}
	}

	flag = false;
	if(x[0]==x[1])
	{
		if(x[2]==x[3] && x[0]!=x[2])
		{
			if((y[0]==y[2]&&y[1]==y[3]&&y[0]!=y[1]) ||(y[0]==y[3]&&y[1]==y[2]&&y[0]!=y[1]))
				flag = true;
		}
	}
	else
	{
		if(((y[1]-y[0])*(y[2]-y[0]) == (x[1]-x[0])*(x[0]-x[2]))
			&& ((y[3]-y[1])*(y[1]-y[0]) == (x[3]-x[1])*(x[0]-x[1]))
			&& ((y[3]-y[2])*(y[2]-y[0]) == (x[3]-x[2])*(x[0]-x[2])))
			flag = true;
	}

	cout<<"result:\t"<<flag<<endl;

	return 0;
}
