/*
 * function: convert string to int
 *
 * author:	dongbeibei
 * time:	2013/8/30
 */

#include <iostream>

using namespace std;

bool inputInvalid = false;

int StrToIntInner(const char *str, bool minus)
{
	long long result = 0;

	while(*str != '\0')
	{
		if(*str>='0' && *str<='9')
		{
			int flag = minus ? -1 : 1;
			result = result * 10 + flag * (*str - '0');

			if((minus && result<(signed int)0x80000000) || (!minus && result>0x7FFFFFFF))
			{
				inputInvalid = true;
				return 0;
			}
			++str;
		}
		else
		{
			inputInvalid = true;
			return 0;
		}
	}

	return result;
}

int StrToInt(const char *str)
{
	inputInvalid = false;

	if(str==NULL || *str=='\0')
	{
		inputInvalid = true;
		return 0;
	}

	bool flag = false;
	bool minus = false;

	while(*str != '\0')
	{
		if(!flag && *str=='+')
		{
			flag = true;
			++str;
		}
		else if(!flag && *str=='-')
		{
			flag = true;
			minus = true;
			++str;
		}
		else if(*str>='0' && *str<='9')
		{
			long long result = StrToIntInner(str, minus);

			return (int)result;
		}
		else
		{
			inputInvalid = true;
			return 0;
		}
	}

	inputInvalid = true;

	return 0;
}

//follow: Unit Test
//the inner test result
void Test(const char *name, const char *array, int exceptedResult, bool exceptedFlag);
//
void test1();
//
void test2();
//
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

void Test(const char *name, const char *array, int exceptedResult, bool exceptedFlag)
{
	if(name != NULL)
		cout<<name<<": ";

	if(StrToInt(array)==exceptedResult && inputInvalid==exceptedFlag)
		cout<<"Passed."<<endl;
	else
		cout<<"Failed."<<endl;
}

void test1()
{
	Test("Test 1", "12345", 12345, false);
	Test("Test 2", "-12345", -12345, false);
	Test("Test 3", "1", 1, false);
	Test("Test 4", "-1", -1, false);
}

void test2()
{
	Test("Test 5", "", 0, true);
	Test("Test 6", "+", 0, true);
	Test("Test 7", "-", 0, true);
}

void test3()
{
	Test("Test 8", "123456781234", 0, true);
	Test("Test 9", "-123456781234", 0, true);
}
