/*
 * find a path sumup of a bintree
 * author: dongbeibei
 * building time: 2013/6/9
 * modifing time: 2013/6/10
 */


#include <iostream>
#include <vector>

using namespace std;

struct BSTreeNode
{
	int			m_nValue;
	BSTreeNode	*m_pLeft;
	BSTreeNode	*m_pRight;
};

int i = 0, j = 0;
int *route;
void init_tree(BSTreeNode *&, int *);

void find(BSTreeNode *, int, int &, vector<int> &);

int main(void)
{
	BSTreeNode *test, *head;

	head = test = NULL;
	int array[] = {10, 5, 4, 0, 0, 7, 0, 0, 12, 0, 0};
	init_tree(test, array);
	

	cout<<test->m_nValue<<endl;
	cout<<test->m_pLeft->m_pRight->m_nValue<<endl;
	//cout<<test->m_pLeft<<endl;

	vector<int> path;
	int currentsum = 0;
	find(test, 22, currentsum, path);

	return 0;
}

/*
 * "root" must be "*&root", forbid the root moving
 */
void init_tree(BSTreeNode *&root, int *array)
{
	int ch;

//	cout<<"input the value:\t";
//	cin>>ch;
	ch = array[i];
	if(++i > 10)
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

void find(BSTreeNode *root, int sum, int &currentsum, vector<int> &path)
{
	//cout<<"000\n";
	if(root == NULL)
		return;

	int key = root->m_nValue;
	bool isLeaf = !(root->m_pLeft) && !(root->m_pRight);
	
	currentsum += key;
	path.push_back(key);

	if(currentsum == sum && isLeaf)
	{
		vector<int>::iterator iter;
		cout<<"path:\t";
		for(iter=path.begin() ; iter!=path.end() ; iter++)
		{
			cout<<*iter<<"  ";
		}
		cout<<endl;
	}

	if(root->m_pLeft)
		find(root->m_pLeft, sum, currentsum, path);
	if(root->m_pRight)
		find(root->m_pRight, sum, currentsum, path);

	currentsum -= key;
	path.pop_back();
}
