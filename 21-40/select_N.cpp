/*
һ����β����������(m ��)����N ����ɫ(N<=10)��
���һ���㷨��ȡ������һ�Σ�Ҫ���������N ����ɫ����ʹ������̡�
������ʱ�临�Ӷ���ռ临�Ӷȡ�
 *
 * author:	dongbeibei
 * time:		2013/6/18
 */


#include <iostream>

using namespace std;

int shortestFullColor(int a[], int n, int m);

int main(void)
{
	int test[] = {0,0,1,3,0,2,1,3};
	int len = sizeof(test)/sizeof(int);
	int m = 3;
	int result;

	result = shortestFullColor(test, len, m);

	cout<<"result:\t"<<result<<endl;

	return 0;
}

int shortestFullColor(int a[], int n, int m)
{
	int c[m], ctr = m;
	int h=0, t=0;
	int min=n;

	for(int i=0 ; i<m ; i++)
		c[i] = 0;
	
	while(1)
	{
		while(ctr >= 0 && h<n)
		{
			if(c[a[h]] == 0)
				ctr--;
			c[a[h]] ++;
			h++;
		}

		if(h>=n)
			return min;

		while (1)
		{
			c[a[t]]--;
			if(c[a[t]] == 0)
				break;

			t++;
		}

		if(min > h-t)
			min = h-t;

		t++;
		ctr++;
	}
}
