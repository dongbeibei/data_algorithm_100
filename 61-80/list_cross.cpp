/*
找出链表的第一个公共结点。
题目：两个单向链表，找出它们的第一个公共结点。
链表的结点定义为：
struct ListNode
{
int m_nKey;
ListNode* m_pNext;
};
分析：这是一道微软的面试题。微软非常喜欢与链表相关的题目，
因此在微软的面试题中，链表出现的概率相当高。
 *
 * author:	dongbeibei
 * time:		2013/6/20
 */


#include <iostream>

using namespace std;

struct ListNode
{
	int			m_nKey;
	ListNode	*m_pNext;
};

int list_init(ListNode *&head, int *array, int len);
int list_visit(ListNode *head);
int list_delete(ListNode *head);

void list_first_cross(ListNode *head1, ListNode *head2, ListNode *&first_cross);

int main(void)
{
	int test[] = {1,2,3,4,5,6,7};
	int len = sizeof(test)/sizeof(int);
	ListNode *head;
	int flag;

	if((flag=list_init(head, test, len)) < 0)
	{
		cout<<"list init fail."<<endl;
		return -1;
	}
	list_visit(head);
	//list_delete(head);

	ListNode *head2;
	head2 = new ListNode;
	head2->m_nKey = 10;
	head2->m_pNext = head->m_pNext;
	list_visit(head2);

	ListNode *cross;
	list_first_cross(head, head2, cross);
	cout<<"result:\t"<<cross->m_nKey<<endl;

	return 0;
}

int list_init(ListNode *&head, int *array, int len)
{
	if(!len)
	{
		head = NULL;
		return 1;
	}

	ListNode *temp, *prev;
	//bool flag;

	//flag = true;
	for(int i=0 ; i<len ; i++)
	{
		temp = new ListNode;
		if(!temp)
		{
			cout<<"the new method is failing."<<endl;
			return -2;
		}
		temp->m_nKey = array[i];
		temp->m_pNext = NULL;

		if(!i)
			head = temp;
		else
			prev->m_pNext = temp;
		prev = temp;
	}

	return 0;
}

int list_visit(ListNode *head)
{
	if(!head)
	{
		cout<<"the list is empty!"<<endl;
		return 0;
	}

	cout<<"the data is:\n\t";
	while(head)
	{
		cout<<head->m_nKey<<"  ";
		if(head->m_pNext)
			head = head->m_pNext;
		else
			break;
	}
	cout<<endl;

	return 1;
}

int list_delete(ListNode *head)
{
	if(!head)
	{
		cout<<"the list is empty."<<endl;
		return 1;
	}
	ListNode *prev;
/*	
	while(head)
	{
		prev = head;
		if(head->m_pNext)
		{
			head = head->m_pNext;
			delete prev;
		}
		else
		{
			delete prev;
			break;
		}
	}
*/
	while(head && head->m_pNext)
	{
		prev = head;
		head = head->m_pNext;
		delete prev;
	}
	delete head;
	
	return 0;
}

void list_first_cross(ListNode *head1, ListNode *head2, ListNode *&first_cross)
{
	if(!head1 || !head2)
		first_cross = NULL;

	ListNode *test1, *fast, *slow;

	test1 = head1;
	while(test1->m_pNext)
		test1 = test1->m_pNext;
	test1->m_pNext = head2;

	fast = slow = head1;
	do
	{
		fast = fast->m_pNext->m_pNext;
		slow = slow->m_pNext;
	}while(fast->m_pNext != slow->m_pNext);

	fast = head1;
	while(fast->m_pNext != slow->m_pNext)
	{
		fast = fast->m_pNext;
		slow = slow->m_pNext;
	}

	first_cross = fast->m_pNext;

	test1->m_pNext = NULL;
}
