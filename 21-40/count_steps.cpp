/*
题目：一个台阶总共有n 级，如果一次可以跳1 级，也可以跳2 级。
求总共有多少总跳法，并分析算法的时间复杂度。
这道题最近经常出现，包括MicroStrategy 等比较重视算法的公司
都曾先后选用过个这道题作为面试题或者笔试题。
 *
 * author:	dongbeibei
 * time:		2013/6/12
 *
 * another method: a[n] record the result, in a oridinary way(from 1 to n)
 */


#include <iostream>

using namespace std;

int fib(int n);

int main(void)
{
	int		n;

	cout<<"input the total steps:\t";
	cin>>n;

	cout<<"the total methods:\t"<<fib(n)<<endl;

	return 0;
}

int fib(int n)
{
	if(n == 1)
		return 1;
	else if(n == 2)
		return 2;
	else
		return fib(n-1)+fib(n-2);
}
