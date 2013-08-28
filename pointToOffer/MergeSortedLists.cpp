/*
 * function:	merge two sorted linklist
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

ListNode *MergeSortedLists(ListNode *pHead1, ListNode *pHead2)
{
	if(pHead1 = NULL)
		return pHead2;
	else if(pHead2 == NULL)
		return pHead1;

	ListNode *pMergeHead=NULL;

	if(pHead1->m_nValue < pHead2->m_nValue)
	{
		pMergeHead = pHead1;
		pMergeHead->m_pNext = MergeSortedLists(pHead1->m_pNext, pHead2);
	}
	else
	{
		pMergeHead = pHead2;
		pMergeHead->m_pNext = MergeSortedLists(pHead1, pHead2->m_pNext);
	}

	return pMergeHead;
}


//follow: Unit Test
//display the linklist
void display(ListNode **pHead);
//two lists both have n nodes: n > 0
void test1();
//one list is empty, one list has n nodes: n > 0
void test2();
//two lists both are empty
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
	cout<<endl;
}

void test1()
{
	ListNode *list1, *list2;
	ListNode *pHead, *prev, *temp;
	
	prev = new ListNode;
	prev->m_nValue = 1;
	prev->m_pNext = NULL;
	list1 = prev;
	for(int i=1 ; i<5 ; ++i)
	{
		temp = new ListNode;
		temp->m_nValue = i*2 + 1;
		temp->m_pNext = NULL;
		prev->m_pNext = temp;
		prev = temp;
	}
	//list1 = pHead;
	
	prev = new ListNode;
	prev->m_nValue = 2;
	prev->m_pNext = NULL;
	list2 = prev;
	for(int i=2 ; i<=5 ; ++i)
	{
		temp = new ListNode;
		temp->m_nValue = i*2;
		temp->m_pNext = NULL;
		prev->m_pNext = temp;
		prev = temp;
	}
	//list2 = pHead;

	cout<<"Test 1:\n";
	cout<<"\tlist1:";
	display(&list1);
	cout<<"\tlist2:";
	display(&list2);
	ListNode *pMergeNode = MergeSortedLists(list1, list2);
	display(&pMergeNode);
}

void test2()
{
	
}

void test3()
{
	
}
