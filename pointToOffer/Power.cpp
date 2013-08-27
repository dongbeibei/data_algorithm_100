/*
 * function: implement the double power
 *
 * author:	dongbeibei
 * time:	2013/8/27
 */

#include <iostream>

using namespace std;

bool invalidInput = false;

bool equal(double i, double j)
{
	if(i-j>-0.000001 && i-j<0.000001)
		return true;
	else
		return false;
}

double absPower(double base, unsigned int absExp)
{
	if(absExp == 0)
		return 1;
	if(absExp == 1)
		return base;

	double result = absPower(base, absExp>>1);
	result *= result;
	if(absExp & 0x1 == 1)
		result *= base;

	return result;
}

double Power(double base, int exp)
{
	invalidInput = false;

	if(equal(base, 0.0) && exp<0)
	{
		invalidInput = true;
		return 0.0;
	}

	unsigned int absExp = (unsigned int)exp;
	if(exp < 0)
		absExp = (unsigned int)(-exp);

	double result = absPower(base, absExp);
	if(exp < 0)
		result = 1/result;

	return result;
}

//follow: Unit Test
void test1();
void test2();
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

//exp > 0
void test1()
{
	double base;
	int exp;

	exp = 3;
	base = 2.5;
	cout<<"Test 1:\n";
	cout<<"except result:\t"<<15.625<<endl;
	cout<<"real result:\t"<<Power(base, exp)<<endl;
	base = 0;
	cout<<"except result:\t"<<0<<endl;
	cout<<"real result:\t"<<Power(base, exp)<<endl;
	base = -2.5;
	cout<<"except result:\t"<<-15.625<<endl;
	cout<<"real result:\t"<<Power(base, exp)<<endl;
}

//exp < 0
void test2()
{
	double base;
	int exp;

	exp = -1;
	base = 2.5;
	cout<<"Test 2:\n";
	cout<<"except result:\t"<<0.4<<endl;
	cout<<"real result:\t"<<Power(base, exp)<<endl;
	base = -2.5;
	cout<<"except result:\t"<<-0.4<<endl;
	cout<<"real result:\t"<<Power(base, exp)<<endl;
}

//invalid input
void test3()
{
	double base;
	int exp;

	base = 0.0;
	exp = -1;
	cout<<"Test 3:\n";
	cout<<"except result:\t"<<"0.0"<<endl;
	cout<<"\tInvalidInput:\t1"<<endl;
	cout<<"real result:\t"<<Power(base, exp)<<endl;
	cout<<"\tInvalidInput:\t"<<invalidInput<<endl;
}
