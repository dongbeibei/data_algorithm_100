/*
�����⣺
������������n ��m��������1��2��3.......n ������ȡ������,
ʹ��͵���m ,Ҫ���������еĿ�������г���.
 *
 * author:	dongbeibei
 * time:		2013/6/12
 */


#include <iostream>
#include <list>

using namespace std;

list<int>	list1;

void find_factor(int sum, int n);

int main(void)
{
	int	sum, n;

	cout<<"input the array number:\t";
	cin>>n;
	cout<<"input the sum_up number:\t";
	cin>>sum;

	cout<<"the result:\n";
	find_factor(sum, n);

	return 0;
}

void find_factor(int sum, int n)
{
	if(sum<=0 || n<=0)
		return;

	if(sum == n)
	{
		for(list<int>::iterator iter=list1.begin() ; iter!=list1.end() ; iter++)
			cout<<*iter<<" + ";
		cout<<n<<endl;
	}

	list1.push_back(n);
	find_factor(sum-n, n-1);
	list1.pop_back();
	find_factor(sum, n-1);
}
