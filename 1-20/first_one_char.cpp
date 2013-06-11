/*
 题目：在一个字符串中找到第一个只出现一次的字符。如输入abaccdeff，则输出b。
 分析：这道题是2006 年google 的一道笔试题。
 *
 * author:	dongbeibei
 * time:		2013/6/11
 */


#include <iostream>
using namespace std;

char first_one_char(char *str);

int main(void)
{
	char *str = "abaccdeff";
	char result;

	result = first_one_char(str);
	cout<<"result:\t"<<result<<endl;
	
	return 0;
}

char first_one_char(char *str)
{
	int test[255];

	for(int i=0 ; i<255 ; i++)
		test[i] = 0;
	char *p = str;
	while(*p != '\0')
	{
		test[*p]++;
		p++;
	}

	p = str;
	while(*p != '\0')
	{
		if(test[*p] == 1)
			return *p;
		p++;
	}

	return '\0';
}
