/*
题目：类CMyString 的声明如下：
class CMyString
{
public:
CMyString(char* pData = NULL);
CMyString(const CMyString& str);
~CMyString(void);
CMyString& operator = (const CMyString& str);
private:
char* m_pData;
};
请实现其赋值运算符的重载函数，要求异常安全，即当对一个对象
进行赋值时发生异常，对象的状态不能改变。
 *
 * author:	dongbeibei
 * time:		2013/6/20
 */


#include <iostream>
#include <string.h>

using namespace std;

class CMyString
{
public:
	CMyString(char *pData = NULL);
	CMyString(const CMyString &str);
	~CMyString(void);
	CMyString& operator=(const CMyString &str);

private:
	char	*m_pData;
};

int main(void)
{
	char *use = "123";
	CMyString test1(use);
	CMyString test2 = test1;

	//cout<<test1.m_pData<<endl;
	//cout<<test2.m_pData<<endl;

	return 0;
}

CMyString::CMyString(char * pData)
{
	m_pData = NULL;
}

CMyString::CMyString(const CMyString & str)
{
	if(this != &str)
		strcpy(m_pData, str.m_pData);
}

CMyString::~CMyString(void)
{
	delete m_pData;
	m_pData = NULL;
}

CMyString& CMyString::operator=(const CMyString &str)
{
	if(this != &str)
	{
		CMyString strtemp(str);

		//char *temp = strtemp->m_pData;
		strcpy(m_pData, strtemp.m_pData);
	}

	return *this;
}