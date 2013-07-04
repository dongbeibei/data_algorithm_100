/*
在一篇英文文章中查找指定的人名，人名使用二十六个英文字母
（可以是大写或小写）、空格以及两个通配符组成（*、？），
通配符"*"表示零个或多个任意字母，通配符"?"表示一个任意字母。

如: "J* Smi??"可以匹配"John Smith"。

用C语言实现如下函数：
void scan(const char *pszText, const char *pszName);
注: pszText为整个文章字符，pszName为要求匹配的英文名。
请完成函数实现输出所有匹配的英文名，除了printf外，
不能使用第三方的库函数。
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
