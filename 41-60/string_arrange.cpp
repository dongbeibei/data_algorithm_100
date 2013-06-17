/*
输入一个字符串，打印出该字符串中字符的所有排列。
例如输入字符串abc，则输出由字符a、b、c 所能排列出来的所有字符串
abc、acb、bac、bca、cab 和cba。
 *
 * author:	dongbeibei
 * time:		2013/6/20
 */


#include <iostream>

using namespace std;

char array[] = {'a', 'b', 'c'};
int len = sizeof(array)/sizeof(char);

void swap(char *array, int i, int j);
void arrange(char *array, int start, int end);

int main(void)
{
	cout<<"len:"<<len<<endl;
	arrange(array, 0, len-1);

	return 0;
}

void swap(char *array, int i, int j)
{
	if(i == j)
		return;

	char	temp;

	temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

void arrange(char * array, int start, int end)
{
	if(start == end)
	{
		cout<<"result:\t";
		for(int i=0 ; i<len ; i++)
			cout<<array[i]<<"  ";
		cout<<endl;
	}
	else
	{
		for(int i=start ; i<=end ; i++)
		{
			swap(array, i, start);
			arrange(array, i+1, end);
			swap(array, i, start);
		}
	}
}