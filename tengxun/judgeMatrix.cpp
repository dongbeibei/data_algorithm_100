/*
��Ŀ�������ĸ�������꣬��֤�ĸ����ǲ��Ǿ���
�ؼ��㣺
1.��������б��֮������-1��
2.���α�������ϵƽ�е�����£�б����������û��жϣ�
3.�����ĵ���ܲ���˳��������Ҫ���ĵ�����
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
