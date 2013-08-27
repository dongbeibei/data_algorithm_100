/*
 * function: Replace the blank in the string.
 *
 * author:	dongbeibei
 * time:	2013/8/27
 */
#include <iostream>
#include <cstring>

using namespace std;

void ReplaceBlank(char str[], const int len)
{
	if(str==NULL || len<=0)
		return;

	char *temp;
	int num, originlen, newlen;

	for(temp=str,num=0,originlen=0 ; *temp!='\0' ; ++temp)
	{
		++originlen;
		if(*temp == ' ')
			++num;
	}

	newlen = originlen + num * 2;
	if(newlen > len)
		return;

	while(originlen>=0 && newlen>originlen)
	{
		if(str[originlen] == ' ')
		{
			str[newlen--] = '0';
			str[newlen--] = '2';
			str[newlen--] = '%';
		}
		else
		{
			str[newlen--] = str[originlen];
		}
		--originlen;
	}
}

//follow: Unit Test
void test1();
void test2();
void test3();
void test4();

int main(void)
{
	test1();
	cout<<endl;
	test2();
	cout<<endl;
	test3();
	cout<<endl;
	test4();

	return 0;
}

void test1()
{
	const int len = 40;
	char str[len] = " I am  a student. ";

	cout<<"Test 1:(every is OK)\n";
	cout<<"origin str:"<<str<<endl;
	ReplaceBlank(str, len);
	cout<<"except result:"<<"\%20I\%20am%20\%20a\%20student.%20"<<endl;
	cout<<"real result:"<<str<<endl;
}

void test2()
{
	const int len = 25;
	char str[len] = " I am  a student. ";

	cout<<"Test 2:(the space is not enough)\n";
	cout<<"origin str:"<<str<<endl;
	ReplaceBlank(str, len);
	cout<<"except result:"<<" I am  a student. "<<endl;
	cout<<"real result:"<<str<<endl;
}

void test3()
{
	const int len = 25;
	char *str = NULL;

	cout<<"Test 3:(the pointer is NULL)\n";
	if(str == NULL)
		cout<<"origin str is NULL"<<endl;
	ReplaceBlank(str, len);
	cout<<"except result:"<<" 1"<<endl;
	cout<<"real result:"<<(str == NULL)<<endl;
}

void test4()
{
	const int len = 25;
	char str[len] = "\0";

	cout<<"Test 4:(the string is empty)\n";
	cout<<"origin str:"<<str<<endl;
	ReplaceBlank(str, len);
	cout<<"except result: 1"<<endl;
	cout<<"real result: "<<(str[0] == '\0')<<endl;
}
