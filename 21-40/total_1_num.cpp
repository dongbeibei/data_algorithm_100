/*
��Ŀ������һ����������������Ķ����Ʊ�����ж��ٸ�1��
��������10������������Ʊ�ʾΪ1010��������1��������2��
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
