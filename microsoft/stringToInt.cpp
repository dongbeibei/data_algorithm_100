/*
 * 写一个函数，检查字符是否是整数，如果是，返回其整数值。
 * (怎样只用4行代码编写出一个从字符串到长整形的函数)
 * 
 *
 * author:	dongbeibei
 * time:		2013/6/28
 */


#include <iostream>
#include <cstring>
#include <limits.h>

using namespace std;

bool Isdigit(const char *test);
long long int stringToInt(const char *test, int len, bool &use); 

int main(void)
{
	const char *test = "+123456";
	int result;
	int len = strlen(test);
	bool flag;

	cout<<"origin:\t"<<test<<endl;
	cout<<Isdigit(test)<<endl;

	result = stringToInt(test, len, flag);
	if(flag)
		cout<<"the input is error."<<endl;
	else
		cout<<"result:\t"<<result<<endl;

	return 0;
}

bool Isdigit(const char *test)
{
	return (*test>='0' && *test<='9');
}

long long int stringToInt(const char *test, int len, bool &use)
{
	int result = 0;
	int flag, i;

	use = false;
	flag = 0;
	if(test[0] == '-')
		flag = -1;
	else if(test[0] == '+')
		flag = 1;

	if(flag)
		i = 1;
	else
		i = 0;

	for( ; i<len ; i++)
	{
		if(Isdigit(test+i))
			result = result * 10 + (*(test+i) - '0');
		else
		{
			 use = true;
			 return 0;
		}
	}

	if(flag)
		return flag * result;
	else
		return result;
}
