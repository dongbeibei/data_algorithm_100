/*
 * function: copy a complex list
 *
 * author:	dongbeibei
 * time:	2013/8/29
 */

#include <iostream>

using namespace std;

struct ComplexListNode
{
	int				m_nValue;
	ComplexListNode	*m_pNext;
	ComplexListNode	*m_pSibling;
};

void nodeCopy(ComplexListNode *pHead);
void copySibling(ComplexListNode *pHead);
ComplexListNode* listCut(ComplexListNode *pHead);
ComplexListNode* Clone(ComplexListNode *pHead);

void nodeCopy(ComplexListNode *pHead)
{
	if(pHead == NULL)
		return;

	ComplexListNode *temp, *pCurNode,*pNextNode;

	pCurNode = pHead;
	while(pCurNode != NULL)
	{
		pNextNode = pCurNode->m_pNext;

		temp = new ComplexListNode;
		temp->m_nValue = pCurNode->m_nValue;
		temp->m_pNext = pNextNode;
		temp->m_pSibling = NULL;

		pCurNode->m_pNext = temp;
		pCurNode = pNextNode;
	}
}

void copySibling(ComplexListNode *pHead)
{
	if(pHead == NULL)
		return;

	ComplexListNode *pCurNode, *pNextNode;

	pCurNode = pHead;
	pNextNode = pHead->m_pNext;
	while(pCurNode != NULL)
	{
		if(pCurNode->m_pSibling)
		{
			pNextNode->m_pSibling = pCurNode->m_pSibling->m_pNext;
		}

		if(pCurNode->m_pNext != NULL)
		{
			pCurNode = pNextNode->m_pNext;
			pNextNode = pCurNode->m_pNext;
		}
		else
			break;
	}
}

ComplexListNode* listCut(ComplexListNode *pHead)
{
	if(pHead == NULL)
		return NULL;

	ComplexListNode *pPrevNode, *pCurNode, *pNextNode;
	ComplexListNode *pNewListHead;

	pNewListHead = pHead->m_pNext;
	pPrevNode = pHead;
	pCurNode = pNewListHead;
	pNextNode = pCurNode->m_pNext;
	while(pCurNode != NULL)
	{
		pPrevNode->m_pNext = pNextNode;
		if(pNextNode != NULL)
			pCurNode->m_pNext = pNexNode->m_pNext;
		else
			break;

		pPrevNode = pNextNode;
		pCurNode = pNextNode->m_pNext;
		pNextNode = pCurNode->m_pNext;
	}
}

//follow: Unit Test
//
void test1();
//
void test2();
//
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
	cout<<"Test 1:\n";


}

void test2()
{
	cout<<"Test 2:\n";


}

void test3()
{
	cout<<"Test 3:\n";


}
