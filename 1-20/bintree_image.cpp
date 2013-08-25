/*
题目：输入一颗二元查找树，将该树转换为它的镜像，
即在转换后的二元查找树中，左子树的结点都大于右子树的结点。
用递归和循环两种方法完成树的镜像转换。
例如输入：
8
/ \
6 10
/\ /\
5 7 9 11
输出：
8
/ \
10 6
/\ /\
11 9 7 5
定义二元查找树的结点为：
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
#include <stack>

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
void reverse_tree_recu(BSTreeNode *root);
void reverse_tree_stack(BSTreeNode *root);
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
	reverse_tree_recu(root);
	//cout<<"222\n";
	Pre_visit(root);
	cout<<endl;
	//cout<<"333\n";
	reverse_tree_stack(root);
	Pre_visit(root);
	cout<<endl;
	//cout<<"444\n";
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

void reverse_tree_recu(BSTreeNode *root)
{	
	if(!(root->m_pLeft || root->m_pRight))
		return;

	if(root->m_pLeft || root->m_pRight)
	{
		BSTreeNode	*temp = new BSTreeNode;
		temp = root->m_pLeft;
		root->m_pLeft = root->m_pRight;
		root->m_pRight = temp;

		temp = NULL;
	}

	reverse_tree_recu(root->m_pLeft);
	reverse_tree_recu(root->m_pRight);
}

void reverse_tree_stack(BSTreeNode * root)
{
	if(root == NULL)
		return;

	stack<BSTreeNode *> s;
	s.push(root);
	while(!s.empty())
	{
		root = s.top();
		s.pop();
	
		BSTreeNode	*temp = new BSTreeNode;
		temp = root->m_pLeft;
		root->m_pLeft = root->m_pRight;
		root->m_pRight = temp;

		temp = NULL;

		if(root->m_pLeft)
			s.push(root->m_pLeft);
		if(root->m_pRight)
			s.push(root->m_pRight);
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
