/*
 * 编程实现两个正整数的除法
 *
 * author:	dongbiebei
 * time:		2013/6/30
 */


#include <iostream>

using namespace std;

int divide(const int x, const int y);

int main(void)
{
	int x = 80;
	int y = 9;

	cout<<"result:\t"<<divide(x, y)<<endl;

	return 0;
}

int divide(const int x,const int y)
{
	int temp, result;

	result = 0;
	temp = x;

	temp -= y;
	while(temp > 0)
	{
		result++;
		temp -= y;
	}

	return result;
}

int div(const int x, const int y)
{ 
	int left_num = x; 
	int result = 0; 
	while (left_num >= y)
	{ 
    	int multi = 1; 
    	while (y * multi <= (left_num >> 1))
		{
       		multi = multi << 1; 
    	} 
    	result += multi; 
    	left_num -= y * multi; 
	} 
	return result; 
}
