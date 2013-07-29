/*
 * 寻找第一个只在字符串中出现一次的字符
 */


#include <iostream>

using namespace std;

char find_first_unique_char(const char *str);

int main(void)
{
	const char *str = "afaccde";

	cout<<find_first_unique_char(str)<<endl;

	return 0;
}

char find_first_unique_char(const char *str)
{
	int data[256] = {0};
	const char *p;

	if(str == NULL)
		return '\0';

	p = str;
	while(*p != '\0')
		data[(unsigned char)*p++]++;

	while(*str != '\0')
	{
		if(data[(unsigned char)*str] == 1)
			return *str;

		str++;
	}

	return '\0';
}
