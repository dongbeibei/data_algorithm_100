/*
对称子字符串的最大长度
题目：输入一个字符串，输出该字符串中对称的子字符串的最大长度。

比如输入字符串"google"，由于该字符串里最长的对称子字符串是"goog"，
因此输出4。
 *
 * author:	dongbeibei
 * time:		2013/7/2
 */


#include <iostream>
#include <cstring>

using namespace std;

int maxLen(char *str, int len);

int main(void)
{
	char *str = "googleasdfdsa";
	int len = strlen(str);

	//cout<<len<<endl;
	cout<<"result:\t"<<maxLen(str, len)<<endl;

	return 0;
}

int maxLen(char *str, int len)
{
	if(!str || len<=0)
		return -1;
	else if(len == 1)
		return 1;

	int maxlen, i, step, len_temp;

	maxlen = 0;
	//
	for(i=0 ; i<len ; i++)
	{
		for(step=0 ; i-step>=0&&i+step<len ; step++)
		{
			if(str[i-step] != str[i+step])
				break;
		}
		len_temp = step * 2 - 1;

		if(maxlen < len_temp)
			maxlen = len_temp;
	}

	for(i=0 ; i<len-1 ; i++)
	{
		if(str[i] != str[i+1])
			continue;
		else
		{
			for(step=0 ; i-step>=0&&i+1+step<len ; step++)
			{
				if(str[i-step] != str[i+1+step])
					break;
			}
			len_temp = step * 2;

			if(maxlen < len_temp)
				maxlen = len_temp;
		}
	}

	return maxlen;
}
