/*
题目：输入一个整数，求该整数的二进制表达中有多少个1。
例如输入10，由于其二进制表示为1010，有两个1，因此输出2。
 *
 * author:	dongbeibei
 * time:		2013/6/12
 */


#include <iostream>

using namespace std;

int main(void)
{
	int 	n, i;

	cout<<"input the number:\t";
	cin>>n;

	i = 0;
	while(n)
	{
		n = n&(n-1);
		i++;
	}

	cout<<"result:\t"<<i<<endl;

	return 0;
}
