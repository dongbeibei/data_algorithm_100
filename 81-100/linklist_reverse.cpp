/*
怎样把一个链表掉个顺序（也就是反序，注意链表的边界条件并考虑空链表）
 *
 * author:	dongbeibei
 * time:		2013/6/27
 */


#include <iostream>

using namespace std;

struct ListNode
{
	int			m_nKey;
	ListNode*	m_pNext;
};

bool init_list(ListNode *&node, int *array, int len);
bool del_list(ListNode *&node);
void visit_list(ListNode *node);
void reverse_list(ListNode *&node);

int main(void)
{
	int array[] = {1,2,3,4,5};
	int len = sizeof(array)/sizeof(int);
	ListNode *head;

	init_list(head, array, len);
	visit_list(head);
	reverse_list(head);
	visit_list(head);

	del_list(head);

	return 0;
}

bool init_list(ListNode *&node, int *array, int len)
{
	node = new ListNode;
	node->m_nKey = array[0];
	node->m_pNext = NULL;

	ListNode *temp = node->m_pNext, *pre = node;

	for(int i=1 ; i<len ; i++)
	{
		temp = new ListNode;
		if(!temp)
			return false;
		temp->m_nKey = array[i];
		temp->m_pNext = NULL;
		pre->m_pNext = temp;
		pre = temp;
	}

	return true;
}

bool del_list(ListNode *&node)
{
	ListNode *temp;

	while(node->m_pNext)
	{
		temp = node->m_pNext;
		delete node;
		node = temp;
	}

	delete node;

	return true;
}


void visit_list(ListNode *node)
{
	if(!node)
	{
		cout<<"the linklist is empty!\n";
		return;
	}

	cout<<"element:\t";
	while(node)
	{
		cout<<node->m_nKey<<"  ";
		node = node->m_pNext;
	}
	cout<<endl;
}

void reverse_list(ListNode *&node)
{
	if(!node)
		return;

	ListNode *pre, *cur, *succ;

	pre = NULL;
	cur = node;
	while(cur)
	{
		succ = cur->m_pNext;

		cur->m_pNext = pre;
		pre = cur;
		cur = succ;
	}
	node = pre;
}
