/*
 * function: according a stack push order, identify the pop order is corrent or not
 *
 * author:	dongbeibei
 * time:	2013/8/28
 */

#include <iostream>
#include <stack>

using namespace std;

bool IsPopOrder(const int *pPush, const int *pPop, int len)
{
	bool bIsPossible = false;

	if(pPush!=NULL && pPop!=NULL && len>0)
	{
		const int *pNextPush = pPush;
		const int *pNextPop = pPop;
		stack<int>	stackData;

		while(pNextPop - pPop < len)
		{
			while(stackData.empty() || stackData.top()!=*pNextPop)
			{
				if(pNextPush - pPush == len)
					break;

				stackData.push(*pNextPush);
				++pNextPush;
			}

			if(stackData.top() != *pNextPop)
				break;

			stackData.pop();
			++pNextPop;
		}

		if(stackData.empty() && pNextPop-pPop==len)
			bIsPossible = true;
	}

	return bIsPossible;
}

//follow: Unit Test
//the two arrays is correct
void test1();
//the two arrays is not match
void test2();
//NULL input
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

	int array1[] = {1, 2, 3, 4, 5};
	int array2[] = {4, 5, 3, 2, 1};
	int len = 5;

	cout<<"result:\t"<<IsPopOrder(array1, array2, len)<<endl;
}

void test2()
{
	cout<<"Test 2:\n";

	int array1[] = {1, 2, 3, 4, 5};
	int array2[] = {4, 5, 3, 1, 2};
	int len = 5;

	cout<<"result:\t"<<IsPopOrder(array1, array2, len)<<endl;
}

void test3()
{
	cout<<"Test 3:\n";

	int *array1 = NULL;
	int *array2 = NULL;
	int len = 5;

	cout<<"result:\t"<<IsPopOrder(array1, array2, len)<<endl;
}
