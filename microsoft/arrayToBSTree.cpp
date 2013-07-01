/*
 * 将一个有序数组放到二叉树中
 *
 * author:	dongbeibei
 * time:		2013/6/30
 */


#include <iostream>

using namespace std;

struct BSNode
{
	int		key;
	struct BSNode	*left;
	struct BSNode	*right;
};

void array_to_bstree(int *array, int len, struct BSNode *&root);
void helper(int *array, int start, int end, struct BSNode *&node);

int main(void)
{
	int array[] = {1,2,3,4,5,6};
	int len = sizeof(array)/sizeof(int);
	struct BSNode *root;

	array_to_bstree(array, len, root);

	cout<<root->key<<endl;
	cout<<root->left->right->key<<endl;
	cout<<root->right->left->key<<endl;

	return 0;
}

void array_to_bstree(int *array, int len, struct BSNode *&root)
{
	helper(array, 0, len-1, root);
}

void helper(int *array, int start, int end, struct BSNode *&node)
{
	if(start > end)
		return;

	node = new BSNode;
	if(!node)
	{
		cout<<"new error, could not construct new node."<<endl;
		return;
	}

	int mid = start + (end - start)/2;

	node->key = array[mid];
	node->left = NULL;
	node->right = NULL;
	helper(array, start, mid-1, node->left);
	helper(array, mid+1, end, node->right);
}
