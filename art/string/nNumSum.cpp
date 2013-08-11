/*
 * 在N个数中寻找所有和为M的任意个数
 */


#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>

using namespace std;

list<int> list1;

void find_factor(int sum, int n);

int main(void)
{
	int		sum, n;
	cout<<"intput the sum: ";
	cin>>sum;
	cout<<"input n: ";
	cin>>n;
	cout<<"all results:\n";
	find_factor(sum, n);

	return 0;
}

void find_factor(int sum, int n)
{
	if(n<=0 || sum<=0)
		return;

	if(sum == n)
	{
		list1.reverse();
		copy(list1.begin(), list1.end(), ostream_iterator<int>(cout, "+"));
		cout<<n<<endl;
		list1.reverse();
	}

	list1.push_front(n);
	find_factor(sum-n, n-1);
	list1.pop_front();
	find_factor(sum, n-1);
}
