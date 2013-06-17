/*
用俩个栈实现队列。
题目：某队列的声明如下：
template<typename T> class CQueue
{
public:
CQueue() {}
~CQueue() {}
void appendTail(const T& node); // append a element to tail
void deleteHead(); // remove a element from head
private:
Stack<T> m_stack1;
Stack<T> m_stack2;
};
分析：从上面的类的声明中，我们发现在队列中有两个栈。
 * author:	dongbeibei
 * time:		2013/6/20
 */


#include <iostream>
#include <stack>

using namespace std;

template<typename T> class CQueue
{
public:
	CQueue() {}
	~CQueue() {}
	void appendTail(const T& node); // append a element to tail
	void deleteHead(); // remove a element from head
private:
	stack<T> m_stack1;
	stack<T> m_stack2;
};

int main(void)
{
	

	return 0;
}

template <typename T>
void CQueue::appendTail(const T& node)
{
	m_stack1.push(node);
}

template <typename T>
void CQueue::deleteHead()
{
	if(!m_stack2.empty())
		return m_stack2.pop();
	if(m_stack1.empty())
		cout<<"delete from empty queue."<<endl;
	while(!m_stack1.empty)
	{
		m_stack2.push(m_stack1.top());
		m_stack1.pop();
	}

	return m_stack2.pop();
}