/*
 * ��Ŀ����1+2+��+n��
 * Ҫ����ʹ�ó˳�����for��while��if��else��switch��case �ȹؼ���
 * �Լ������ж���䣨A?B:C����
 *
 * author:	dongbeibei
 * building time:	2013/6/11
 *
 * function: using virtual function
 */


#include <iostream>

using namespace std;

class base
{
public:
	virtual int sum(int n)
	{
		return 0;
	}
};

base *test[2];

class func: public base
{
public:
	virtual int sum(int n)
	{
		return test[!!n]->sum(n-1)+n;
	}
};

int main(void)
{
	int n = 100;

	base a;
	func b;

	test[0] = &a;
	test[1] = &b;

	cout<<"result:\t"<<test[1]->sum(n)<<endl;

	return 0;
}
