/*
 * function: implement a stack with min, min is O(1)
 *
 * author:	dongbeibei
 * time:	2013/8/28
 */

#include <iostream>
#include <stack>
#include <cassert>

using namespace std;

template <typename T>
class StackWithMin
{
public:
	void push(const T& value);
	void pop();
	const T& min() const;
	bool empty() const;

private:
	stack<T> m_data;
	stack<T> m_min;
};

template <typename T>
void StackWithMin<T>::push(const T& value)
{
	m_data.push(value);

	if(m_min.empty() || value<m_min.top())
		m_min.push(value);
	else
		m_min.push(m_min.top());
}

template <typename T>
void StackWithMin<T>::pop()
{
	assert((!m_min.empty()) && (!m_data.empty()));

	m_data.pop();
	m_min.pop();
}

template <typename T>
const T& StackWithMin<T>::min() const
{
	assert((!m_min.empty()) && (!m_data.empty()));

	return m_min.top();
}

template <typename T>
bool StackWithMin<T>::empty() const
{
	if(m_min.empty() && m_data.empty())
		return true;
	else
		return false;
}

//follow: Unit Test
//just one OK
void test1();

int main(void)
{
	test1();
	cout<<endl;

	return 0;
}

void test1()
{
	cout<<"Test 1:\n";

	StackWithMin<int> test;

	test.push(3);
	test.push(5);
	test.push(2);
	test.push(4);
	test.push(6);

	while(!test.empty())
	{
		cout<<test.min()<<endl;
		test.pop();
	}
}
