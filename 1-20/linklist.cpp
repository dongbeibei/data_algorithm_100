/*
 * 题目：输入一个单向链表，输出该链表中倒数第k 个结点。
 * 链表的倒数第0 个结点为链表的尾指针。
* 链表结点定义如下：
struct ListNode
{
int m_nKey;
ListNode* m_pNext;
};
 *
 * author:	dongbeibei
 * building time:	2013/6/11
 */


#include <iostream>

using namespace std;

#define LEN 10

struct ListNode
{
	int			m_nKey;
	ListNode*	m_pNext;
};

//分配内存空间，并初始化链表
bool init_list(ListNode *node, int *array);
//找到倒数第K个节点
bool find_count_back(ListNode *node, ListNode *&result, int k);
//请空链表，释放内存
bool del_list(ListNode *node);

int main(void)
{
	ListNode *test;
	int array[LEN];

	for(int i=0 ; i<LEN ; i++)
		array[i] = i+1;

	test = new ListNode;
	test->m_nKey = 0;
	test->m_pNext = NULL;
	init_list(test, array);

	cout<<test->m_nKey<<endl;
	cout<<test->m_pNext->m_nKey<<endl;

	ListNode *result = new ListNode;
	int key = 4;

	if(find_count_back(test, result, key))
		cout<<"result:"<<result->m_nKey<<"  "<<result->m_pNext->m_nKey<<endl;
	else
		cout<<"the "<<key<<"th count back doesn't exist!"<<endl;

	del_list(test);

	return 0;
}

bool init_list(ListNode *node, int *array)
{
	ListNode *temp = node->m_pNext, *pre = node;

	for(int i=0 ; i<LEN ; i++)
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

bool del_list(ListNode *node)
{
	ListNode *temp, *pre;

	pre = node;
	while(pre->m_pNext)
	{
		temp = pre->m_pNext;
		delete pre;
		pre = temp;
	}

	delete pre;

	return true;
}

bool find_count_back(ListNode *node, ListNode *&result, int k)
{
	int i;
	ListNode *temp = new ListNode;

	temp = node;
	if(node==NULL)
	{
		if(k==0)
		{
			result = node;
			return true;
		}
		else
			return false;
	}
		
	for(i=1 ; node->m_pNext!=NULL ; i++)
		node = node->m_pNext;

	if(k>i)
		return false;

	node = temp;
	for(int j=0 ; j<i-k ; j++)
	{
		node = node->m_pNext;
	}

	result = node;

	return true;
}
