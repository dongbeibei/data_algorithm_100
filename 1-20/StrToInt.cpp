/*
 ��Ŀ������һ����ʾ�������ַ������Ѹ��ַ���ת���������������
 ���������ַ���"345"�����������345��
 *
 * author:	dongbeibei
 * time:		2013/6/11
 */


#include <iostream>
#include <cstring>

using namespace std;

int main(void)
{
	char	*origin, *test;
	char	temp;
	int		len, result;

	cout<<"input the string:\t";
	cin>>origin;

	test = const_cast<char *>(origin);
	len = strlen(test);
	//cout<<len<<endl;

	result = 0;
	for(int i=0 ; i<len ; i++)
	{
		temp = *(test+i);

		if(temp>='0' && temp<='9')
			result = result*10 + (temp-'0');
		else
		{
			cout<<"the input is error\n";
			return -1;
		}
		//cout<<"result:\t"<<result<<endl;
	}

	cout<<"result:\t"<<result<<endl;

	return 0;
}
