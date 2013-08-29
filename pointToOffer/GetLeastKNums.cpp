/*
 * function: get the least K numbers in the array
 *
 * author:	dongbeibei
 * time:	2013/8/29
 */

#include <iostream>

using namespace std;

void GetLeastKNums(int *input, int len, int *output, int k)
{
	if(input==NULL || output==NULL || len<=0 || k<=0 || k>len)
		return;

	int start = 0;
	int end = len - 1;
	int index = partition(input, len, start, end);
	while(index != k-1)
	{
		if(index > k-1)
		{
			end = index - 1;
			index = partition(input, len, start, end);
		}
		else
		{
			start = index + 1;
			index = partition(input, len, start, end);
		}
	}

	for(int i=0 ; i<k ; ++i)
		output[i] = input[i];
}

typedef multiset<int, greater<int> >			intSet;
typedef multiset<int, greater<int> >::iterator	setIterator;

void GetLeastKNums_2(const vector<int>& data, intSet& leastKNums, int k)
{
	leastKNums.clear();

	if(k<1 || data.size() < k)
		return;

	vector<int>::const_iterator iter = data.begin(), rear = data.end();
	for( ; iter!=rear ; ++iter)
	{
		if(leastKNums.size() < k)
		{
			leastKNums.insert(*iter);
		}
		else
		{
			setIterator greatest = leastKNums.begin();

			if(*iter < *greatest)
			{
				leastKNums.erase(greatest);
				leasrKNums.insert(*iter);
			}
		}
	}
}

//follow: Unit Test
//
void test1();
//
void test2();
//
void test3();

int main(void)
{
	test1();
	cout<<endl;
	test2();
	cout<<endl;
	test3();

	return 0;
}

void test1()
{
	cout<<"Test 1:\n";


}

void test2()
{
	cout<<"Test 2:\n";


}

void test3()
{
	cout<<"Test 3:\n";


}
