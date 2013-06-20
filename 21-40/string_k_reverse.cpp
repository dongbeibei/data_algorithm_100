/*
�����ַ���������ת���������ַ���ǰ������ɸ��ַ��ƶ����ַ���
��β��������ַ���abcdef ����ת2 λ�õ��ַ���cdefab����ʵ���ַ���
����ת�ĺ�����

Ҫ��ʱ��Գ���Ϊn ���ַ��������ĸ��Ӷ�ΪO(n)�������ڴ�ΪO(1)��
 *
 * author:	donebeibei
 * time:		2013/6/12
 */


#include <iostream>
#include <cstring>

using namespace std;

void string_k_reverse(char *str, int k, int len);
void string_rev(char *str, int k);

int main(void)
{
	char test[] = "abcdef";
	int len, k;

	k = 2;
	len = sizeof(test)/sizeof(char)-1;

	string_k_reverse(test, k, len);

	cout<<"result:\t"<<test<<endl;

	return 0;
}

void string_k_reverse(char *str, int k, int len)
{
	string_rev(str, len-k);
	string_rev(str+len-k, k);
	string_rev(str, len);
}

void string_rev(char *str, int k)
{
	int i = 0;
	char temp;

	k--;
	while(i < k)
	{
		temp = str[i];
		str[i] = str[k];
		str[k] = temp;
		//*(str+i) = *(str+k-1);
		//*(str+k-1) = temp;

		i++;
		k--;
	}
}