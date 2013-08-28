/*
 * function: reverse the linklist
 *
 * author:	dongbeibei
 * time:	2013/8/28
 */


#include <iostream>

using namespace std;

struct ListNode
{
	int			m_nValue;
	ListNode	*m_pNext;
};

void ListReverse(ListNode **pHead)
{
	if(*pHead==NULL || (*pHead)->m_pNext==NULL)
		return;

	ListNode *prev, *cur, *next;
	prev = *pHead;
	cur = prev->m_pNext;
	next = cur->m_pNext;

	prev->m_pNext = NULL;
	while(next != NULL)
	{
		cur->m_pNext = prev;
		prev = cur;
		cur = next;
		next = cur->m_pNext;
	}
	cur->m_pNext = prev;

	*pHead = cur;
}

//follow: Unit Test
//display the Linklist
void display(ListNode **pHead);
//n nodes(n > 1)
void test1();
//1 nodes
void test2();
//NULL
void test3();

int main(void)
{
	test1();
	cout<<endl;
	test2();
	cout<<endl;
	test3();

	return 0;
}

void display(ListNode **pHead)
{
	if(*pHead == NULL)
		return;

	ListNode *temp = *pHead;
	while(temp != NULL)
	{
		cout<<temp->m_nValue<<" ";
		temp = temp->m_pNext;
	}
}

void test1()
{
	ListNode *pHead, *prev, *temp;
	
	prev = new ListNode;
	prev->m_nValue = 1;
	prev->m_pNext = NULL;
	pHead = prev;

	for(int i=2 ; i<=5 ; ++i)
	{
		temp = new ListNode;
		temp->m_nValue = i;
		temp->m_pNext = NULL;
		prev->m_pNext = temp;
		prev = temp;
	}

	cout<<"Test 1:\n";
	cout<<"except result:\t"<<"5 4 3 2 1 "<<endl;
	cout<<"real result:\t";
	ListReverse(&pHead);
	display(&pHead);
	cout<<endl;
}

void test2()
{
	ListNode *pHead = new ListNode;
	pHead->m_nValue = 1;
	pHead->m_pNext = NULL;

	cout<<"Test 2:\n";
	cout<<"except result:\t"<<"1 "<<endl;
	cout<<"real result:\t";
	ListReverse(&pHead);
	display(&pHead);
	cout<<endl;
}

void test3()
{
	ListNode *pHead = NULL;

	cout<<"Test 3:\n";
	cout<<"except result:\t"<<""<<endl;
	cout<<"real result:\t";
	ListReverse(&pHead);
	display(&pHead);
	cout<<endl;
}
