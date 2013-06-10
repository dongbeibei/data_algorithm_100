/*
 * convert a bintree to a doubly linked list
 * author: dongbeibei
 * building time: 2013/6/8
 * modifing time: 2013/6/9
 */


#include <iostream>
#include <stack>

using namespace std;

struct BSTreeNode
{
	int			m_nValue;
	BSTreeNode	*m_pLeft;
	BSTreeNode	*m_pRight;
};

void init_tree(BSTreeNode *&);
void Pre_visit(BSTreeNode *);
void In_visit(BSTreeNode *);
void Post_visit(BSTreeNode *);
void In_visit_1(BSTreeNode *);
void convert_1(BSTreeNode *);
void convert_2(BSTreeNode *);

BSTreeNode *pre = NULL;

int main(void)
{
	BSTreeNode *test, *head;

	head = test = NULL;
	init_tree(test);
	

	cout<<test->m_nValue<<endl;
	//cout<<test->m_pLeft->m_nValue<<endl;
	cout<<test->m_pLeft<<endl;

	cout<<"Pre_visit:\n";
	Pre_visit(test);
	cout<<endl;

	cout<<"In_visit:\n";
	In_visit(test);
	cout<<endl;

	cout<<"In_visit:\n";
	In_visit_1(test);
	cout<<endl;

	cout<<"Post_visit:\n";
	Post_visit(test);
	cout<<endl;

	cout<<"-----------convert---------------\n";
	cout<<"convert:\n";
	convert_1(test);
	cout<<"000\n";
	cout<<test->m_nValue<<endl;
	cout<<test->m_pLeft->m_pRight->m_nValue<<endl;
	cout<<test->m_pRight->m_pLeft->m_nValue<<endl;
	cout<<test->m_pLeft->m_nValue<<endl;
	cout<<test->m_pRight->m_nValue<<endl;
	cout<<endl;

	return 0;
}

/*
 * "root" must be "*&root", forbid the root moving
 */
void init_tree(BSTreeNode *&root)
{
	int ch;

	cout<<"input the value:\t";
	cin>>ch;
	if(ch != 0)
	{
		cout<<"222\n";
		if(!(root = new BSTreeNode))
		{
			cout<<"malloc fail\n";
		}
		root->m_nValue = ch;
		root->m_pLeft = NULL;
		root->m_pRight = NULL;

		init_tree(root->m_pLeft);
		init_tree(root->m_pRight);
	}

	//cout<<"value:\t"<<root->m_nValue<<endl;
}

void Pre_visit(BSTreeNode *root)
{
	if(root == NULL)
		return;

	cout<<root->m_nValue<<"  ";
	Pre_visit(root->m_pLeft);
	Pre_visit(root->m_pRight);
}

void In_visit(BSTreeNode *root)
{
	if(root == NULL)
		return;

	In_visit(root->m_pLeft);
	cout<<root->m_nValue<<"  ";
	In_visit(root->m_pRight);
}

void Post_visit(BSTreeNode *root)
{
	if(root == NULL)
		return;

	Post_visit(root->m_pLeft);
	Post_visit(root->m_pRight);
	cout<<root->m_nValue<<"  ";
}

//using stack to Inorder visit the bintree
void In_visit_1(BSTreeNode *root)
{
	stack<BSTreeNode*>	s;
	BSTreeNode *p = root, *q;

	while(p || !s.empty())
	{
		while(p)
		{
			s.push(p);
			p = p->m_pLeft;
		}

		if(!s.empty())
		{
			p = s.top();
			cout<<p->m_nValue<<"  ";
			s.pop();
			p = p->m_pRight;
		}
	}
}

void convert_1(BSTreeNode *root)
{
	//cout<<"111\n";
	if(root != NULL)
	{
		convert_1(root->m_pLeft);
		root->m_pLeft = pre;
		if(pre)
			pre->m_pRight = root;
		pre = root;
		convert_1(root->m_pRight);
	}
	else
		return;
}
