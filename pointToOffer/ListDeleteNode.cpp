/*
 * function: given the linklist and the deleted node pointer, delete it in O(1) time
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
//suppose the ListNode is really in the list
void DeleteNode(ListNode **pHead, ListNode *pToDeleted)
{
	if(*pHead == NULL && pToDeleted == NULL)
		return;

	if(pToDeleted->m_pNext != NULL)
	{
		ListNode *temp = pToDeleted->m_pNext;
		pToDeleted->m_nValue = temp->m_nValue;
		pToDeleted->m_pNext = temp->m_pNext;
		
		delete temp;
		temp = NULL;
	}
	else if(pToDeleted == *pHead)
	{
		delete pToDeleted;
		pToDeleted = NULL;
		*pHead = NULL;
	}
	else
	{
		ListNode *temp = *pHead;
		while(temp->m_pNext != pToDeleted)
			temp = temp->m_pNext;
		temp->m_pNext = NULL;
		delete pToDeleted;
		pToDeleted = NULL;
	}
}

//oridinary condition
bool DeleteListNode(ListNode **pHead, ListNode *pToDeleted)
{
	if(*pHead == NULL)
	{
		if(pToDeleted == NULL)
			return true;
		else
			return false;
	}

	ListNode *temp = *pHead;
	while(temp->m_pNext!=pToDeleted)
	{
		temp = temp->m_pNext;
		if(temp == NULL)
			return false;
	}

	if(pToDeleted->m_pNext == NULL)
	{
		temp->m_pNext = NULL;
		delete pToDeleted;
		pToDeleted = NULL;
	}
	else
	{
		temp->m_nValue = pToDelete->m_nValue;
		temp->m_pNext = pToDeleted->m_pNext;
		delete pToDeleted;
		pToDeleted = NULL;
	}

	return true;
}
