/*
 ��Ŀ������Fibonacci �������£�
 / 0 n=0
 f(n)= 1 n=1
 \ f(n-1)+f(n-2) n=2
 ����n�������ķ���������еĵ�n �
 *
 * author:	dongbeibei
 * time:		2013/6/11
 */

#include <iostream>

using namespace std;

int main(void)
{
	int n;

	cout<<"input the number:\t";
	cin>>n;

	int fn[n+1];

	fn[0] = 0;
	fn[1] = 1;

	for(int i=2; i<n+1 ; i++)
		fn[i] = fn[i-1] + fn[i-2];

	cout<<"f("<<n<<") = "<<fn[n]<<endl;

	return 0;
}
