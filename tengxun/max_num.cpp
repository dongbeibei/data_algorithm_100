/*
定义一个宏，比较两个数a、b的大小，不能使用<，>和if语句
 *
 * author:	dongbeibei
 * time:		2013/7/2
*/


#include <iostream>

using namespace std;

#define max1(x, y) (1-(((x-y)>>31)&1))*x + (((x-y)>>31)&1)*y
#define max2(x, y) (1-((x>>31)&1))*x + ((x>>31)&1)*y
#define max(x, y) (1-((x^y)>>31)&1)*max1(x,y) + (((x^y)>>31)&1)*max2(x,y)

int main(void)
{
	int x, y;

	cout<<"input the first number:   \t";
	cin>>x;
	cout<<"input the second number:  \t";
	cin>>y;

	cout<<"the max in "<<x<<" and "<<y<<" is:\t"<<max(x,y)<<endl;

	return 0;
}
