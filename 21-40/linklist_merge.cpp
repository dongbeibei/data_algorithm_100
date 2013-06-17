/*
链表操作，
（1）.单链表就地逆置，
（2）合并链表
 *
 * author:	dongbeibei
 * time:		2013/6/12
 */


#include <iostream>

using namespace std;

struct ListNode
{
	int			m_nVaule;
	ListNode	*m_pNext;
};

void init_List(ListNode *&head, int *array, int len);
void visit_List(ListNode *head);
void reverse_List(ListNode *&head);
void merge_List(ListNode *&head, ListNode *head1, ListNode *head2);
void del_List(ListNode *&head);

int main(void)
{
	int array1[] = {7,5,3,1};
	int array2[] = {2,4,6,8};
	int len1, len2;
	ListNode	*head1, *head2, *merge;

	len1 = sizeof(array1)/sizeof(int);
	init_List(head1, array1, len1);
	
	len2 = sizeof(array2)/sizeof(int);
	init_List(head2, array2, len2);

	visit_List(head1);
	reverse_List(head1);
	cout<<"----------reverse--------"<<endl;
	visit_List(head1);
	visit_List(head2);

	//merge = new ListNode;
	merge_List(merge ,head1, head2);
	visit_List(merge);

	del_List(merge);

	return 0;
}

void init_List(ListNode *&head, int *array, int len)
{
	ListNode *pre = new ListNode;

	for(int i=0 ; i<len ; i++)
	{
		ListNode *temp = new ListNode;
		temp->m_nVaule = array[i];
		temp->m_pNext = NULL;

		if(i==0)
			head = temp;
		else
			pre->m_pNext = temp;

		pre = temp;
	}
}
void visit_List(ListNode *head)
{
	cout<<"visit:\t";
	while(head)
	{
		cout<<head->m_nVaule<<"  ";
		if(head->m_pNext)
			head = head->m_pNext;
		else
			break;
	}
	cout<<endl;
}

void reverse_List(ListNode *&head)
{
	if(head == NULL)
		return;

	ListNode	*pre, *next;

	pre = new ListNode;
	next = new ListNode;

	pre = NULL;
	next = head->m_pNext;
	while(head != NULL)
	{
		head->m_pNext = pre;

		pre = head;
		head = next;
		if(head == NULL)
			break;
		else
			next = head->m_pNext;
	}
	
	head = pre;
	pre = NULL;
	next = NULL;
}

void merge_List(ListNode *&head, ListNode *head1, ListNode *head2)
{
	ListNode	*temp;

	if(!head1)
	{
		head = head1;
		return;
	}

	if(!head2)
	{
		head = head2;
		return;
	}

	if(head1->m_nVaule < head2->m_nVaule)
	{
		head = head1;
		head1 = head1->m_pNext;
	}
	else
	{
		head = head2;
		head2 = head2->m_pNext;
	}

	temp = head;
	while(head1 && head2)
	{
		if(head1->m_nVaule < head2->m_nVaule)
		{
			temp->m_pNext = head1;
			temp = head1;
			head1 = head1->m_pNext;
		}
		else
		{
			temp->m_pNext = head2;
			temp = head2;
			head2 = head2->m_pNext;
		}
	}

	if(head1)
		temp->m_pNext = head1;
	else
		temp->m_pNext = head2;
}

void del_List(ListNode *&head)
{
	ListNode	*pre;

	pre = head;
	while(pre)
	{
		if(head->m_pNext)
		{
			head = head->m_pNext;
			delete pre;
		}
		else
		{
			delete pre;
			break;
		}

		pre = head;
	}
}
