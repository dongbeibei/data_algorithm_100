/*
��һƪӢ�������в���ָ��������������ʹ�ö�ʮ����Ӣ����ĸ
�������Ǵ�д��Сд�����ո��Լ�����ͨ�����ɣ�*��������
ͨ���"*"��ʾ�������������ĸ��ͨ���"?"��ʾһ��������ĸ��

��: "J* Smi??"����ƥ��"John Smith"��

��C����ʵ�����º�����
void scan(const char *pszText, const char *pszName);
ע: pszTextΪ���������ַ���pszNameΪҪ��ƥ���Ӣ������
����ɺ���ʵ���������ƥ���Ӣ����������printf�⣬
����ʹ�õ������Ŀ⺯����
 *
 * author:	dongbeibei
 * time:		2013/7/4
 */


#include <iostream>

using namespace std;

const char *pEnd = NULL;

bool match(const char *pszText, const char *pszName);
void scan(const char *pszText, const char *pszName);

int main(void)
{
	const char *text = "John SmithJon Smith";
	const char *name = "J* Smi??";

	scan(text, name);

	return 0;
}

bool match(const char *pszText, const char *pszName)
{
	if(*pszName == '\0')
	{
		pEnd = pszText;
		return true;
	}

	if(*pszText == '\0')
	{
		if(*pszName=='*')
		{
			pEnd = pszText;
			return true;
		}

		//pszText++;
		return false;
	}

	if(*pszName!='*' && *pszName!='?')
	{
		if(*pszName == *pszText)
		{
			return match(pszText+1, pszName+1);
		}

		return false;
	}
	else
	{
		if(*pszName == '*')
			return match(pszText,pszName+1)||match(pszText+1,pszName);
		else
			return match(pszText+1, pszName+1);
	}
}

void scan(const char *pszText, const char *pszName)
{
	if(!pszName || !pszText)
	{
		cout<<"the input string is error.\n";
		return;
	}

	while(*pszText != '\0')
	{
		if(match(pszText, pszName))
		{
			while(pszText != pEnd)
				cout<<*pszText++;
			cout<<endl;
		}
	}
}
