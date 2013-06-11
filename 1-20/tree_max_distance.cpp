/*
 *  ��������нڵ��������...
 *  ������ǰѶ���������һ��ͼ�����ӽڵ�֮������߿�����˫��ģ�
 *  ���ǹ��Ҷ���"����"Ϊ���ڵ�֮��ߵĸ�����
 *  дһ��������һ�ö������������Զ�������ڵ�֮��ľ��롣
 *
 * author:	dongbeibei
 * building time:	2013/6/11
 */

#include <iostream>

using namespace std;

int i = 0;
int array[] = {1, 2, 4, 7, 0, 0, 0, 5, 0, 0, 3, 0, 0};
int j = sizeof(array)/sizeof(int);

struct BSTreeNode
{
	int			m_nValue;
	BSTreeNode	*m_pLeft;
	BSTreeNode	*m_pRight;
};

void init_tree(BSTreeNode *&root, int *array);
int max(int a, int b);
int helper(BSTreeNode *root, int &depth);
int maxDistance(BSTreeNode * root);

int main(void)
{
	BSTreeNode *test;

	init_tree(test, array);

	int distance = maxDistance(test);

	cout<<"distance:"<<distance<<endl;

	return 0;
}

void init_tree(BSTreeNode *&root, int *array)
{
	int ch;

//	cout<<"input the value:\t";
//	cin>>ch;
	ch = array[i];
	if(++i > j)
		return;
	if(ch != 0)
	{
		//cout<<"222\n";
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

	//cout<<"value:\t"<<root->m_nValue<<endl;
}

int max(int a, int b)
{
	return ((a>b)?a:b);
}

int helper(BSTreeNode *root, int &depth)
{
	int ld, rd, maxleft, maxright;

	if(root == NULL)
	{
		depth = 0;
		return 0;
	}

	maxleft = helper(root->m_pLeft, ld);
	maxright = helper(root->m_pRight, rd);

	depth = max(ld, rd)+1;

	return max(maxleft, max(maxright, ld+rd));
}

int maxDistance(BSTreeNode * root)
{
	int depth;
	
	return helper(root, depth);
}
