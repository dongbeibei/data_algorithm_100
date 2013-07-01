/*
 * 给出一个函数来输出所有字符串的排列。
 * 
 * author:	dongbeibei
 * time:		2013/6/28
*/


#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;

void mySwap(char *array, int i, int j);
void arrayAllArrange(char *array);
void helper(char *array, int start, int end);

int main(void)
{
	char test[] = "abc";

	arrayAllArrange(test);

	return 0;
}

void mySwap(char *array, int i, int j)
{
	if(i == j)
		return;

	char temp;
	temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

void arrayAllArrange(char *array)
{
	char *temp;
	int i = 0;

	temp = array;
	while(*temp != '\0')
	{
		i++;
		temp++;
	}

	cout<<i<<endl;
	helper(array, 0, i-1);
}

void helper(char *array, int start, int end)
{
	if(start == end)
	{
		cout<<array<<endl;
	}
	else
	{
		for(int pos=start ; pos<=end ; pos++)
		{
			mySwap(array, pos, start);
			helper(array, start+1, end);
			mySwap(array, pos, start);
		}
	}
}
