/*
��Ŀ��΢����
����һ�Ŷ�Ԫ�����������°����ӡ����ÿ����㣬ͬһ���а��մ������ҵ�˳���ӡ��
��������
7
8
/ \
6 10
/ \ / \
5 7 9 11
���8 6 10 5 7 9 11��

�����Ԫ�������Ľ��Ϊ��
struct BSTreeNode // a node in the binary search tree (BST)
{
int m_nValue; // value of node
BSTreeNode *m_pLeft; // left child of node
BSTreeNode *m_pRight; // right child of node
};
 *
 * author:	dongbeibei
 * building time:	2013/6/11
 */


#include <iostream>
#include <queue>

using namespace std;

struct BSTreeNode // a node in the binary search tree (BST)
{
	int			m_nValue; // value of node
	BSTreeNode *m_pLeft; // left child of node
	BSTreeNode *m_pRight; // right child of node
};

int i=0;
#define LEN 14

void init_tree(BSTreeNode *&root, int *array);
void queue_visit(BSTreeNode *root);
void Pre_visit(BSTreeNode *root);
void del_tree(BSTreeNode *root);

int main(void)
{
	int array[] = {8,6,5,0,0,7,0,0,10,9,0,0,11,0,0};
	//int array[] = {2,1,0,0,3,0,0};
	BSTreeNode *root;

	//cout<<"000\n";
	init_tree(root, array);
	Pre_visit(root);
	cout<<endl;
	//cout<<"111\n";
	cout<<"result:\n\t";
	queue_visit(root);
	cout<<endl;
	//cout<<"333\n";
	del_tree(root);

	return 0;
}

void init_tree(BSTreeNode *&root, int *array)
{
	int ch;

	ch = array[i];
	if(++i > LEN)
		return;
	if(ch != 0)
	{
		if(!(root = new BSTreeNode))
		{
			cout<<"malloc fail\n";
		}
		root->m_nValue = ch;
		root->m_pLeft = NULL;
		root->m_pRight = NULL;

		init_tree(root->m_pLeft, array);
		init_tree(root->m_pRight, array);
	}

}

void queue_visit(BSTreeNode * root)
{
	if(root == NULL)
		return;

	queue<BSTreeNode *> s;

	s.push(root);
	while(!s.empty())
	{
		BSTreeNode *temp = s.front();
		
		cout<<temp->m_nValue<<"  ";
		if(temp->m_pLeft)
			s.push(temp->m_pLeft);
		if(temp->m_pRight)
			s.push(temp->m_pRight);

		s.pop();
	}
}

void Pre_visit(BSTreeNode *root)
{
	if(root == NULL)
		return;

	cout<<root->m_nValue<<"  ";
	Pre_visit(root->m_pLeft);
	Pre_visit(root->m_pRight);
}

void del_tree(BSTreeNode *root)
{
	if(root == NULL)
		return;

	del_tree(root->m_pLeft);
	del_tree(root->m_pRight);

	delete root;
}
