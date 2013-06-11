/*
 * function:	find if two linklist is reclosing?
 * author:	dongbeibei
 * building time:	2013/6/10
 * modifing time:	
 * website:		http://blog.csdn.net/zyq0335/article/details/7553011
 */


#include <iostream>

using namespace std;

struct linklist_elem
{
	int				data;
	linklist_elem	*next;
};

struct linklist
{
	linklist_elem	*head;
};

//判断无环链是否相交，即判断其最后一个节点是否相同，时间复杂度O(length1 + length2)
bool linklist_reclosing(linklist *h1, linklist *h2);
//判断有环链是否相交，即通过判断第一条链的最后一个节点是否存在于第二条链为基准
bool linklist_loop_reclosing(linklist *h1, linklist *h2);
//找到链表的倒数第2个节点，即item->next != NULL && item->next->next == NULL
struct linklist_elem *find(linklist *test);
//判断链表是否存在环，使用快慢指针
bool IsExitLoop(linklist *test);
//找到链表的入环节点，如果不存在环则返回NULL
struct linklist_elem *findLoopPort(linklist *test);

int main(void)
{
	linklist	*h1, *h2, *h3;
	linklist_elem	*temp, *test, *link;
	
	h1 = new linklist;
	h2 = new linklist;
	h3 = new linklist;
	h1->head = new linklist_elem;
	h2->head = new linklist_elem;
	h3->head = new linklist_elem;

	link = new linklist_elem;

	h1->head->data = 1;
	h1->head->next = NULL;

	for(int i = 0 ; i<10 ; i++)
	{
		temp = new linklist_elem;
		temp->data = i+2;
		temp->next = NULL;
		if(i == 0)
			h1->head->next = temp;
		else
			link->next = temp;

		link = temp;

		if(i == 5)
		{
			h2->head->data = 2;
			h2->head->next = temp;
		}
	}

		
	h3->head->data = 1;
	h3->head->next = NULL;
/*
	cout<<"h1:"<<h1->head->data<<endl;
	cout<<h1->head->next->next->data<<endl;
	cout<<"h2:"<<h2->head->data<<endl;
	cout<<h2->head->next->data<<endl;
*/

	cout<<"result_1:\t"<<linklist_reclosing(h1, h2)<<endl;
	cout<<"result_2:\t"<<linklist_reclosing(h1, h3)<<endl;

	return 0;
}

bool linklist_reclosing(linklist *h1, linklist *h2)
{
	linklist_elem *p, *q;

	p = find(h1);
	q = find(h2);

	if(p->next == q->next)
		return true;
	else
		return false;
}

bool linklist_loop_reclosing(linklist *h1, linklist *h2)
{
	linklist_elem	*p, *q;

	p = find(h1);
	q = h2->head;
	while(q->next)
	{
		if(q == p->next)
			return true;
		q = q->next;
	}

	return false;
}

struct linklist_elem *find(linklist *test)
{
	linklist_elem	*p, *q;

	q = p = test->head;
	while((p->next))
	{
		q = p;
		p = p->next;
	}

	return q;
}

bool IsExitLoop(linklist *test)
{
	linklist_elem	*slow, *fast;

	slow = fast = test->head;

	while(fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;

		if(slow == fast)
			break;
	}

	return !(fast==NULL || fast->next==NULL);
}

struct linklist_elem *findLoopPort(linklist *test)
{
	linklist_elem	*slow, *fast;

	slow = fast = test->head;

	while(fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;

		if(slow == fast)
			break;
	}

	if(fast==NULL || fast->next==NULL)
		return NULL;

	slow = test->head;
	while(slow != fast)
	{
		slow = slow->next;
		fast = fast->next;
	}

	return slow;
}
