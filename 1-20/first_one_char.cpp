/*
 ��Ŀ����һ���ַ������ҵ���һ��ֻ����һ�ε��ַ���������abaccdeff�������b��
 �������������2006 ��google ��һ�������⡣
 *
 * author:	dongbeibei
 * time:		2013/6/11
 */


#include <iostream>
using namespace std;

char first_one_char(char *str);

int main(void)
{
	char *str = "abaccdeff";
	char result;

	result = first_one_char(str);
	cout<<"result:\t"<<result<<endl;
	
	return 0;
}

char first_one_char(char *str)
{
	int test[255];

	for(int i=0 ; i<255 ; i++)
		test[i] = 0;
	char *p = str;
	while(*p != '\0')
	{
		test[*p]++;
		p++;
	}

	p = str;
	while(*p != '\0')
	{
		if(test[*p] == 1)
			return *p;
		p++;
	}

	return '\0';
}
