/*
�������ַ����е��ַ�'*'�Ƶ�����ǰ���֣�ǰ��ķ�'*'�ַ����ƣ�������
�ı��'*'�ַ����Ⱥ�˳�򣬺������ش����ַ�'*'��������

��ԭʼ��Ϊ��ab**cd**e*12�������Ϊ*****abcde12��
����������ֵΪ5����Ҫ��ʹ�þ����ٵ�ʱ��͸����ռ䣩
 *
 * author:	dongbeibei
 * time:		2013/6/28
 */


#include <iostream>
#include <cstring>

using namespace std;

void stringswap(string &str, int i, int j);
int stringMove(string &str);

int main(void)
{
	string test = "ab**cd**e*12";

	int len = test.length();
	cout<<len<<endl;

	cout<<test<<endl;

	cout<<stringMove(test)<<endl;
	cout<<test<<endl;

	return 0;
}

void stringswap(string &str, int i, int j)
{
	if(i == j)
		return;

	char temp;
	temp = str[i];
	str[i] = str[j];
	str[j] = temp;
}

int stringMove(string &str)
{
	int len = str.length();
	int count = 0;
	int i, j;

	i = j = len - 1;
	while(i >= 0)
	{
		if(str[i] != '*')
			stringswap(str, i-- , j--);
		else
		{
			i--;
			count++;
		}
	}

	return count;
}
