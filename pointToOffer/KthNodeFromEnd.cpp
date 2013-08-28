/*
 * function: find the Kth node from the end of the linklist
 *
 * author:	dongbeibei
 * time:	2013/8/28
 */


#include <iostream>
//#include <exception>

using namespace std;

struct ListNode
{
	int			m_nValue;
	ListNode	*m_pNext;
};

ListNode *KthNodeFromEnd(ListNode **pHead, int kth)
{
	if(pHead==NULL || kth<=0)
		return NULL;

	ListNode *index1 = *pHead, *index2;
	int i = 0;
	index2 = index1;
	while(i<kth)
	{
		if(index2 == NULL)
			return NULL;
		index2 = index2->m_pNext;
		++i;
	}

	while(index2)
	{
		index2 = index2->m_pNext;
		index1 = index1->m_pNext;
	}

	return index1;
}

//follow: Unit Test
//the linklist has n nodes, n>=k
void test1();
//the linklist has n nodes, n<k
void test2();
//the linklist is empty
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
	ListNode *found;
	for(int i=0 ; i<=5 ; ++i)
	{
		found = KthNodeFromEnd(&pHead, i);
		cout<<"result "<<i<<"thFromEnd:\t";
		if(found != NULL)
			cout<<"yes"<<"\tValue: "<<found->m_nValue;
		else
			cout<<"no";
		cout<<endl;
	}
}

void test2()
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

	cout<<"Test 2:\n";
	ListNode *found;
	for(int i=0 ; i<=6 ; ++i)
	{
		found = KthNodeFromEnd(&pHead, i);
		cout<<"result "<<i<<"thFromEnd:\t";
		if(found != NULL)
			cout<<"yes"<<"\tValue: "<<found->m_nValue;
		else
			cout<<"no";
		cout<<endl;
	}
}

void test3()
{
	ListNode *pHead = NULL;

	cout<<"Test 3:\n";
	ListNode *found;
	for(int i=0 ; i<=3 ; ++i)
	{
		found = KthNodeFromEnd(&pHead, i);
		cout<<"result "<<i<<"thFromEnd:\t";
		if(found != NULL)
			cout<<"yes"<<"\tValue: "<<found->m_nValue;
		else
			cout<<"no";
		cout<<endl;
	}
}
