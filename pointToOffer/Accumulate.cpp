/*
 * function: count 1+2+3+......+n, can not use *, /, ?: et.
 *
 * method:
 *			1. 构造函数和静态成员变量 
 *			2. 函数指针
 *			3. 模板类型和模板特例化
 *			4. 虚函数
 *
 * author:	dongbeibei
 * time:	2013/8/30
 */

#include <iostream>

using namespace std;

class Base;
Base *Array[2];

class Base
{
public:
	virtual int accumulate(int n)
	{
		return 0;
	}
};

class Drived: public Base
{
public:
	int accumulate(int n)
	{
		return Array[!!n]->accumulate(n-1) + n;
	}
};

int sum(int n)
{
	Base a;
	Drived b;

	Array[0] = &a;
	Array[1] = &b;

	int value = Array[1]->accumulate(n);

	return value;
}

//follow: Unit Test
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

void test1()
{
	cout<<"Test 1:\n";


}

void test2()
{
	cout<<"Test 2:\n";


}

void test3()
{
	cout<<"Test 3:\n";


}
