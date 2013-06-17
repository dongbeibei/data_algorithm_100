/*
题目：输入一个正数n，输出所有和为n 连续正数序列。
例如输入15，由于1+2+3+4+5=4+5+6=7+8=15，所以输出3 个连续序列1-5、4-6 和7-8。
 *
 * author:	dongbeibei
 * time:		2013/6/19
 */


#include <iostream>

using namespace std;

int main(void)
{
	int n;
	cin>>n;

	for(int i=2 ; i<=n/2 ; i++)
	{
		if(n%i == 0)
		{
			if((i&1) == 0)
				continue;
			else
			{
				//cout<<"000\n";
				if((n/i-i/2+1)<=0)
					continue;
				cout<<"i:"<<i<<endl;
				cout<<n/i-(i-1)/2<<" - "<<n/i+(i-1)/2<<endl;
			}
		}
		else
		{
			if((((float)n)/i - n/i) == 0.5)
			{
				//cout<<(float)n/i<<endl;
				if((n/i-(i-2)/2) <= 0)
					continue;
				cout<<"i:"<<i<<endl;
				cout<<n/i-(i-2)/2<<" - "<<n/i+i/2<<endl;
			}
			else
				continue;
		}
	}

	return 0;
}
