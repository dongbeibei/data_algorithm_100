/*
���ַ�����ɾ���ض����ַ���
��Ŀ�����������ַ������ӵ�һ�ַ�����ɾ���ڶ����ַ���������
���ַ������磬����"They are students."��"aeiou"�� ��ɾ��֮��ĵ�һ���ַ���
���"Thy r stdnts."��

����������һ��΢�������⡣��΢��ĳ����������У����ַ������
����Ŀռ�˺ܴ��һ���֣���Ϊд��������ַ����ܺܺõ�
��ӳ���ǵı�̻�������
 *
 * author:	dongbeibei
 * time:		2013/6/21
 */


#include <iostream>

using namespace std;

int delete_char(char *str, int str_len, char *sample, int sample_len);

int main(void)
{
	char str[] = "They are students.";
	char sample[] = "aeiou";
	int str_len = sizeof(str)/sizeof(char);
	int sample_len = sizeof(sample)/sizeof(char);

	cout<<str<<endl;
	cout<<sample<<endl;
	delete_char(str, str_len, sample, sample_len);
	cout<<str<<endl;

	return 0;
}

int delete_char(char *str, int str_len, char *sample, int sample_len)
{
	if(!str)
		return -1;

	if(!sample)
		return 0;

	int hash[255];
	int i, j;

	for(i=0 ; i<255 ; i++)
		hash[i] = 0;

	for(i=0 ; i<sample_len ; i++)
		hash[sample[i]] = 1;

	for(i=j=0 ; i<str_len ; i++)
	{
		if(hash[str[i]])
		{
			
		}
		else
		{
			str[j] = str[i];
			j++;
		}
	}
	str[j] = '\0';
	
	return 0;
}
