/*
 * find all the primes sumup to the given number
 * example:
 *	number:	8
 *	result:	2 + 2 + 2 + 2
 			2 + 3 + 3
 			3 + 5
 *
 * author:	feng
 * time:		2013/8/13
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iterator>

using namespace std;

// 计算num内的所有素数（不包括num）
void CalcPrimers(int num, vector<int> &primes);

// 输出所有素数组合(递归实现)
int PrintCombinations(int num, const vector<int> &primes, int from, vector<int> &numbers);

// 计算num的所有素数和分解
int ExpandedGoldbach(int num);


int main()
{
	for(int i=1 ; i<=20 ; ++i)
	{
		cout<<"When i = "<<i<<endl;
		int count = ExpandedGoldbach(i);
		cout<<"Total: "<<count<<endl;
	}

	return 0;
}


void CalcPrimers(int num, vector<int> &primes)
{
	primes.clear();
	if(num <= 2)
		return;

	primes.push_back(2);
	for(int i=3; i<num ; i+=2)
	{
		int root = int(sqrt(i));
		int j = 2;
		for( ; j<=root ; ++j)
			if(i%j == 0)
				break;

		if(j > root)
			primes.push_back(i);
	}
}

int PrintCombinations(int num, const vector<int> &primes, int from, vector<int> &numbers)
{
	if(num == 0)
	{
		cout<<"Found: ";
		copy(numbers.begin(), numbers.end(), ostream_iterator<int>(cout, " "));
		cout<<endl;
		return 1;
	}

	int count = 0;

	// 从第from个素数搜索，从而避免输出同构的多个组合
	int primesNum = primes.size();
	for(int i=from ; i<primesNum ; ++i)
	{
		if(num < primes[i])
			break;
		numbers.push_back(primes[i]);
		count += PrintCombinations(num-primes[i], primes, i, numbers);
		numbers.pop_back();
	}

	return count;
}

int ExpandedGoldbach(int num)
{
	if(num <= 3)
		return 0;

	vector<int> primes;
	CalcPrimers(num, primes);

	vector<int> numbers;
	return PrintCombinations(num, primes, 0, numbers);
}
