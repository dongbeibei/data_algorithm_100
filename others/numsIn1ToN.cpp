/*
 *
 * function: count the numbers of the key appears in 1 to N
 *
 * author: feng
 * time:   2013/9/18
 */


#include <iostream>

using std::cout;
using std::endl;

int numsAppearIn1ToN(int n, int key)
{
	if(n<=0 || key<0)
		return -1;

	int total = 0;
	for(int i=1 ; n/i ; i=i*10)
	{
		int high = n/(i*10);
		int cur = (n/i)%10;
		int low = n - (n/i)*i;

		if(cur < key)
			total += high * i;
		else if(cur == key)
			total += high * i + low + 1;
		else
			total += (high + 1) * i;
	}

	return total;
}

// unit test
void test1();
void test2();
void test(int realResult, int exceptedResult);

int main()
{
	test1();
	cout<<endl<<endl;
	test2();
	cout<<endl<<endl;

	return 0;
}

void test(int realResult, int exceptedResult)
{
	if(realResult == exceptedResult)
		cout<<"Passed."<<endl;
	else
		cout<<"failed."<<endl;
}

void test1()
{
	cout<<"Test 1:"<<endl;

	int n = 0, key = 0;

	test(numsAppearIn1ToN(n,key), -1);

	n = 3;
	key = -2;
	test(numsAppearIn1ToN(n,key), -1);
}

void test2()
{
	cout<<"Test 2:"<<endl;

	int n = 33, key = 3;

	test(numsAppearIn1ToN(n,key), 8);

	n = 32;
	test(numsAppearIn1ToN(n,key), 6);
	n = 29;
	test(numsAppearIn1ToN(n,key), 3);
	n = 2;
	test(numsAppearIn1ToN(n,key), 0);
	n = 12;
	test(numsAppearIn1ToN(n,key), 1);
}
