/*
在字符串中删除特定的字符。
题目：输入两个字符串，从第一字符串中删除第二个字符串中所有
的字符。例如，输入"They are students."和"aeiou"， 则删除之后的第一个字符串
变成"Thy r stdnts."。

分析：这是一道微软面试题。在微软的常见面试题中，与字符串相关
的题目占了很大的一部分，因为写程序操作字符串能很好的
反映我们的编程基本功。
 *
 * author:	dongbeibei
 * time:		2013/6/21
 */


#include <iostream>

using namespace std;

int delete_char(char *str, int str_len, char *sample, int sample_len);

int main(void)
{
	char str[] = "They are students.";
	char sample[] = "aeiou";
	int str_len = sizeof(str)/sizeof(char);
	int sample_len = sizeof(sample)/sizeof(char);

	cout<<str<<endl;
	cout<<sample<<endl;
	delete_char(str, str_len, sample, sample_len);
	cout<<str<<endl;

	return 0;
}

int delete_char(char *str, int str_len, char *sample, int sample_len)
{
	if(!str)
		return -1;

	if(!sample)
		return 0;

	int hash[255];
	int i, j;

	for(i=0 ; i<255 ; i++)
		hash[i] = 0;

	for(i=0 ; i<sample_len ; i++)
		hash[sample[i]] = 1;

	for(i=j=0 ; i<str_len ; i++)
	{
		if(hash[str[i]])
		{
			
		}
		else
		{
			str[j] = str[i];
			j++;
		}
	}
	str[j] = '\0';
	
	return 0;
}
