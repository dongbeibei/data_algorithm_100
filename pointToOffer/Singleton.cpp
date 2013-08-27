/*
 * function: implement Singleton
 *
 * author:	dongbeibei
 * time:	2013/8/26
 */

#include <iostream>

using namespace std;

class Singleton
{
public:
	static Singleton* GetInstance()
	{
		if(m_pInstance == NULL)
			m_pInstance = new Singleton();

		return m_pInstance;
	}

private:
	Singleton() {};
	static Singleton* m_pInstance;
};

Singleton* Singleton::m_pInstance = NULL;

//follow: Unit Test
void test(void);

int main()
{
	test();

	return 0;
}

void test(void)
{
	Singleton *p1 = Singleton::GetInstance();
	Singleton *p2 = Singleton::GetInstance();

	cout<<"Test:"<<endl;
	cout<<"except result:\t1"<<endl;
	cout<<"real result:\t"<<(p1==p2)<<endl;
}
