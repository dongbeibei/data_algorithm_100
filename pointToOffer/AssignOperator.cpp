/*
 * function: implement assgin operator
 *
 * author:	dongbeibei
 * time:	2013/8/26
 */

#include <iostream>
#include <cstring>

using namespace std;

class CMyString
{
public:
	CMyString(char *pData = NULL);
	CMyString(const CMyString& str);
	~CMyString();

	CMyString& operator=(const CMyString& str);
	void print();

private:
	char *m_pData;
};

CMyString::CMyString(char *pData)
{
	if(pData == NULL)
	{
		m_pData = new char[1];
		m_pData[0] = '\0';
	}
	else
	{
		int len = strlen(pData);
		m_pData = new char[len+1];
		strcpy(m_pData, pData);
	}
}

CMyString::CMyString(const CMyString& str)
{
	int len = strlen(str.m_pData);
	m_pData = new char[len+1];
	strcpy(m_pData, str.m_pData);
}

/*
CMyString& CMyString::operator=(const CMyString& str)
{
	if(this == &str)
		return *this;

	int len = strlen(str.m_pData);
	m_pData = new char[len+1];
	strcpy(m_pData, str.m_pData);

	return *this;
}
*/

CMyString& CMyString::operator=(const CMyString& str)
{
	if(this != &str)
	{
		CMyString tmp(str);

		char *strTmp = tmp.m_pData;
		tmp.m_pData = m_pData;
		m_pData = strTmp;
	}

	return *this;
}

CMyString::~CMyString()
{
	delete []m_pData;
}

void CMyString::print()
{
	cout<<m_pData<<endl;
}

//the follow: use to unit test
void test1(void);
void test2(void);
void test3(void);

int main()
{
	test1();
	test2();
	test3();

	return 0;
}

void test1()
{
	const char *origin = "Hello World.";
	char *str = const_cast<char*>(origin);
	CMyString use1(str);
	CMyString use2;
	use2 = use1;

	cout<<"Test 1:"<<endl;
	cout<<"except result:\t"<<str<<endl;
	cout<<"real result:\t";
	use2.print();
	cout<<endl;
}

void test2()
{
	const char *origin = "Hello World.";
	char *str = const_cast<char*>(origin);
	CMyString use1(str);
	use1 = use1;

	cout<<"Test 2:"<<endl;
	cout<<"except result:\t"<<str<<endl;
	cout<<"real result:\t";
	use1.print();
	cout<<endl;
}

void test3()
{
	const char *origin = "Hello World.";
	char *str = const_cast<char*>(origin);
	CMyString use1(str);
	CMyString use2, use3;
	use3 = use2 = use1;

	cout<<"Test 3:"<<endl;
	cout<<"except result:\t"<<str<<endl;
	cout<<"real result:\t";
	use2.print();
	cout<<"real result:\t";
	use3.print();
	cout<<endl;
}

