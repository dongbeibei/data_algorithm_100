/*
��һ���д�Сд��ɵ��ַ�����������Ҫ���������޸ģ������е�����
Сд��ĸ���ڴ�д��ĸ��ǰ�棨��д��Сд֮�䲻Ҫ�󱣳�ԭ�����򣩣�
����п��ܾ���ѡ��ʱ��Ϳռ�Ч�ʸߵ��㷨
c���Ժ���ԭ��void proc��char *str����
 *
 * author:	dongbeibei
 * time:		2013/7/1
 */


#include <iostream>

using namespace std;

void myswap(char *a, char *b);
void proc(char *str);

int main(void)
{
	char str[] = "abaDFGdfDSsB";

	cout<<str<<endl;
	proc(str);
	cout<<str<<endl;

	return 0;
}

void proc(char *str)
{
	char *temp;
	int i, j, len;

	temp = str;
	len = 0;
	while(*temp != '\0')
	{
		len++;
		temp++;
	}

	for(i=0, j=len-1 ; i<j ; )
	{
		while(str[i]>='a' && str[i]<='z')
			i++;
		while(str[j]>='A' && str[j]<='Z')
			j--;
		if(i<j)
			myswap(&str[i], &str[j]);
	}
}

void myswap(char *a, char *b)
{
	char temp = *a;
	*a = *b;
	*b = temp;
}
