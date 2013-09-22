/*
 * function:
 *
 * author:	dongbeibei
 * time:
 */

#include <iostream>

using namespace std;





//follow: Unit Test
//the inner test result
void Test(const char *name, const char *array, int exceptedResult);
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

void Test(const char *name, const char *array, int exceptedResult)
{
	if(name != NULL)
		cout<<name<<": ";

	if()
		cout<<"Passed."<<endl;
	else
		cout<<"Failed."<<endl;
}

void test1()
{

}

void test2()
{

}

void test3()
{

}
