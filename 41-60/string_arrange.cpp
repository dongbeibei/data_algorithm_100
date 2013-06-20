/*
����һ���ַ�������ӡ�����ַ������ַ����������С�
���������ַ���abc����������ַ�a��b��c �������г����������ַ���
abc��acb��bac��bca��cab ��cba��
 *
 * author:	dongbeibei
 * time:		2013/6/20
 */


#include <iostream>

using namespace std;

char array[] = {'a', 'b', 'c'};
int len = sizeof(array)/sizeof(char);

void swap(char *array, int i, int j);
void arrange(char *array, int start, int end);

int main(void)
{
	cout<<"len:"<<len<<endl;
	arrange(array, 0, len-1);

	return 0;
}

void swap(char *array, int i, int j)
{
	if(i == j)
		return;

	char	temp;

	temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

void arrange(char * array, int start, int end)
{
	if(start == end)
	{
		cout<<"result:\t";
		for(int i=0 ; i<len ; i++)
			cout<<array[i]<<"  ";
		cout<<endl;
	}
	else
	{
		for(int i=start ; i<=end ; i++)
		{
			swap(array, i, start);
			arrange(array, i+1, end);
			swap(array, i, start);
		}
	}
}