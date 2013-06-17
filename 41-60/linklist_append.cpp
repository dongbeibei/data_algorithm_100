/*
42.请修改append 函数，利用这个函数实现：
两个非降序链表的并集，1->2->3 和2->3->5 并为1->2->3->5
另外只能输出结果，不能修改两个链表的数据。
 *
 * author:	dongbeibei
 * time:		2013/6/19
 */


#include <iostream>

using namespace std;

struct ListNode
{
	int			data;
	ListNode	*next;
};

void list_init(ListNode *&head, int *elem, int len);
void list_visit(ListNode *head);
void list_delete(ListNode *head);
ListNode *list_append(ListNode *head1, ListNode *head2);

int main(void)
{
	int elem1[] = {1,3,4,5,7};
	ListNode *head1;
	int len1 = sizeof(elem1)/sizeof(int);

	list_init(head1, elem1, len1);
	list_visit(head1);

	int elem2[] = {3,5,6,7,8};
	ListNode *head2;
	int len2 = sizeof(elem2)/sizeof(int);

	list_init(head2, elem2, len2);
	list_visit(head2);

	ListNode *merge;

	merge = list_append(head1, head2);
	list_visit(merge);

	list_delete(head1);
	list_delete(head2);
	list_delete(merge);

	return 0;
}

void list_init(ListNode *&head, int *elem, int len)
{
	int i;
	ListNode *temp, *prev;

	if(!len)
	{
		head = NULL;
		return;
	}

	//temp = head;
	for(i=0 ; i<len ; i++)
	{
		temp = new ListNode;
		if(!temp)
			cout<<"new fail."<<endl;
		temp->data = elem[i];
		temp->next = NULL;

		if(i)
			prev->next = temp;
		else
			head = temp;

		prev = temp;
	}
}

void list_visit(ListNode *head)
{
	ListNode *temp;

	temp = head;
	if(!temp)
	{
		cout<<"the list is empty."<<endl;
		return;
	}
	cout<<"the data:\n\t";
	while(temp)
	{
		cout<<temp->data<<"  ";
		if(temp->next)
			temp = temp->next;
		else
			break;
	}
	cout<<endl;
}

void list_delete(ListNode *head)
{
	ListNode *next;

	while(head)
	{
		if(head->next)
			next = head->next;
		else
			next = NULL;

		delete head;
		
		if(next)
			head = next;
		else
			break;
	}
}

ListNode *list_append(ListNode *head1, ListNode *head2)
{
	ListNode *merge, *head, *prev;
	bool flag = true;

	while(head1 && head2)
	{
		merge = new ListNode;

		if(head1->data < head2->data)
		{
			merge->data = head1->data;
			head1 = head1->next;
		}
		else if(head1->data > head2->data)
		{
			merge->data = head2->data;
			head2 = head2->next;
		}
		else
		{
			merge->data = head1->data;
			head1 = head1->next;
			head2 = head2->next;
		}
		merge->next = NULL;

		if(flag)
		{
			head = merge;
			flag = false;
		}
		else
			prev->next = merge;
		prev = merge;
	}

	while(head1)
	{
		merge = new ListNode;
		merge->data = head1->data;
		merge->next = NULL;
		head1 = head1->next;
		
		if(flag)
		{
			head = merge;
			flag = false;
		}
		else
			prev->next = merge;
		prev = merge;
	}

	while(head2)
	{
		merge = new ListNode;
		merge->data = head2->data;
		merge->next = NULL;
		head2 = head2->next;
		
		if(flag)
		{
			head = merge;
			flag = false;
		}
		else
			prev->next = merge;
		prev = merge;
	}

	return head;
}
