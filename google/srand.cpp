/*
给定能随机生成整数1到5的函数，写出能随机生成整数1到7的函数
 *
 * author:	dongbeibei
 * time:		2013/7/1
 */


#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

int base(void);
int func(void);

int main(void)
{
	cout<<"result:\t"<<func()<<endl;

	return 0;
}

int base(void)
{
	srand(time(NULL));

	return rand()%5 + 1;
}

int func(void)
{
	int a;

	while((a=base()*5+base())>26);

	return (a-3)/3;
}
