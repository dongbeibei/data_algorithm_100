/*
 * function: print the list in reversed way
 *
 * author:	dongbeibei
 * time:	2013/8/27
 */

#include <iostream>
#include <stack>

using namespace std;

struct ListNode
{
	int			m_nValue;
	ListNode	*m_pNext;
};

void Print(ListNode *pHead)
{
	stack<ListNode*> nodes;
	ListNode *temp;

	temp = pHead;
	while(temp != NULL)
	{
		nodes.push(temp);
		temp = temp->m_pNext;
	}

	while(!nodes.empty())
	{
		temp = nodes.top();
		cout<<temp->m_nValue<<" ";
		nodes.pop();
	}
}

//follow: Unit Test
//test1: the List has 3 nodes
//test2: the List has only 1 node
//test3: the List is empty
void test1();
void test2();
void test3();

int main(void)
{
	test1();
	cout<<endl;
	test2();
	cout<<endl;
	test3();
	cout<<endl;

	return 0;
}

void test1()
{
	ListNode *pHead = new ListNode;
	ListNode *root;

	root = pHead;
	pHead->m_nValue = 1;
	pHead->m_pNext = NULL;

	for(int i=2 ; i<=10 ; ++i)
	{	
		ListNode *temp = new ListNode;
		temp->m_nValue = i;
		temp->m_pNext = NULL;
		pHead->m_pNext = temp;
		pHead = temp;
	}
	
	cout<<"Test1:\n";
	cout<<"except result: "<<"1 2 3 4 5 6 7 8 9 10 "<<endl;
	cout<<"real result: ";
	Print(root);
	cout<<endl;
}

void test2()
{	
	ListNode *pHead = new ListNode;

	pHead->m_nValue = 1;
	pHead->m_pNext = NULL;

	cout<<"Test2:\n";
	cout<<"except result: "<<"1 "<<endl;
	cout<<"real result: ";
	Print(pHead);
	cout<<endl;
}

void test3()
{
	ListNode *pHead = NULL;

	cout<<"Test3:\n";
	cout<<"except result: "<<endl;
	cout<<"real result: ";
	Print(pHead);
	cout<<endl;
}
