/*
函数将字符串中的字符'*'移到串的前部分，前面的非'*'字符后移，但不能
改变非'*'字符的先后顺序，函数返回串中字符'*'的数量。

如原始串为：ab**cd**e*12，处理后为*****abcde12，
函数并返回值为5。（要求使用尽量少的时间和辅助空间）
 *
 * author:	dongbeibei
 * time:		2013/6/28
 */


#include <iostream>
#include <cstring>

using namespace std;

void stringswap(string &str, int i, int j);
int stringMove(string &str);

int main(void)
{
	string test = "ab**cd**e*12";

	int len = test.length();
	cout<<len<<endl;

	cout<<test<<endl;

	cout<<stringMove(test)<<endl;
	cout<<test<<endl;

	return 0;
}

void stringswap(string &str, int i, int j)
{
	if(i == j)
		return;

	char temp;
	temp = str[i];
	str[i] = str[j];
	str[j] = temp;
}

int stringMove(string &str)
{
	int len = str.length();
	int count = 0;
	int i, j;

	i = j = len - 1;
	while(i >= 0)
	{
		if(str[i] != '*')
			stringswap(str, i-- , j--);
		else
		{
			i--;
			count++;
		}
	}

	return count;
}
