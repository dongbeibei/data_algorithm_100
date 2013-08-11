/*
 * 题目描述:
 * 上千万或上亿数据（有重复），统计其中出现次数最多的前N个数据
 * 解决方案：
 * 1、采用红黑树来进行统计次数。
 * 2、然后遍历整棵树，同时采用最小堆更新前N个出现次数最多的数据。
 */


#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

#define PARENT(i) ((i)/2)
#define LEFT(i) (2*i)
#define RIGHT(i) (2*i+1)

typedef enum rb_color{RED, BLACK}RB_COLOR;
typedef struct rb_node
{
	int key;
	int data;
	RB_COLOR color;
	struct rb_node *left;
	struct rb_node *right;
	struct rb_node *parent;
}RB_NODE;

RB_NODE *RB_CreateNode(int key, int data);
RB_NODE *RB_RotateLeft(RB_NODE *node, RB_NODE *root);
RB_NODE *RB_RotateRight(RB_NODE *node, RB_NODE *root);
RB_NODE *RB_Insert_Rebalance(RB_NODE *node, RB_NODE *root);
RB_NODE *RB_SearchAuxiliary(int key, RB_NODE *root, RB_NODE **save);
RB_NODE *RB_Search(int key, RB_NODE *root);
RB_NODE *RB_Insert(int key, int data, RB_NODE *root);
void InOrderTraverse(RB_NODE *node);
void RB_Destory(RB_NODE *node);

typedef struct rb_heap
{
	int key;
	int data;
}RB_HEAP;
const int heapSize = 10;
RB_HEAP heap[heapSize+1];

void MIN_HEAPIFY(RB_HEAP *A, const int &size, int i);
void BUILD_MINHEAP(RB_HEAP *A, const int &size);

int main(void)
{
	RB_NODE *root = NULL;
	RB_NODE *node = NULL;

	for(int i=1 ; i<=10 ; ++i)
	{
		heap[i].key = i;
		heap[i].data = -i;
	}
	BUILD_MINHEAP(heap, heapSize);

	FILE *fp = fopen("data.txt", "r");
	int num;
	while(!feof(fp))
	{
		fscanf(fp, "%d", &num);
		root = RB_Insert(num, 1, root);
	}
	fclose(fp);

	InOrderTraverse(root);
	RB_Destory(root);

	cout<<"result:\n";
	for(i=1 ; i<=10 ; ++i)
	{
		cout<<"\t"<<heap[i].key<<"\t"<<heap[i].data<<endl;
	}

	return 0;
}


RB_NODE *RB_CreateNode(int key, int data)
{
	RB_NODE *node = new RB_NODE;
	if(NULL == node)
	{
		cout<<"new error!\n";
		exit(-1);
	}

	node->key = key;
	node->data = data;
	node->color = RED;
	node->left = NULL;
	node->right = NULL;
	node->parent = NULL;

	return node;
}

//left rotate
/*
*
*  node                       right
*  / \        ==>             /  \
* a right                   node  y
*     / \                    /  \
*    b  y                   a   b
*
*/
RB_NODE *RB_RotateLeft(RB_NODE *node, RB_NODE *root)
{
	RB_NODE *right = node->right;

	if((node->right = right->left))
		right->left->parent = node;

	right->left = node;

	if((right->parent = node->parent))
	{
		if(node == node->parent->left)
			node->parent->left = right;
		else
			node->parent->right = right;
	}
	else
		root = right;

	node->parent = right;

	return root;
}

//right rotate
/*
*
*     node                       left
*     /   \       ==>           /  \
*   left   y                     a   node
*   / \                                /  \
*  a   b                              b   y
*/
RB_NODE *RB_RotateRight(RB_NODE *node, RB_NODE *root)
{
	RB_NODE *left = node->left;

	if((node->left = left->right))
		left->right->parent = node;

	left->right = node;

	if((left->parent = node->parent))
	{
		if(node == node->parent->right)
			node->parent->right = left;
		else
			node->parent->left = left;
	}
	else
		root = left;

	node->parent = left;

	return root;
}

//insert node
RB_NODE *RB_Insert_Rebalance(RB_NODE *node, RB_NODE *root)
{
	RB_NODE *parent, *gparent, *uncle, *tmp;

	while((parent = node->parent) && parent->color == RED)
	{
		gparent = parent->parent;
		
		if(parent == gparent->left)
		{
			uncle = gparent->right;

			if(uncle && uncle->color == RED)
			{
				uncle->color = BLACK;
				parent->color = BLACK;
				gparent->color = RED;
				node = gparent;
			}
			else
			{
				if(parent->right == node)
				{
					root = RB_RotateLeft(parent, root);
					tmp = parent;
					parent = node;
					node = tmp;
				}

				parent->color = BLACK;
				gparent->color = RED;
				root = RB_RotateRight(gparent, root);
			}
		}
		else
		{
			uncle = gparent->left;

			if(uncle && uncle->color == RED)
			{
				uncle->color = BLACK;
				parent->color = BLACK;
				gparent->color = RED;
				node = gparent;
			}
			else
			{
				if(parent->left == node)
				{
					root = RB_RotateRight(parent, root);
					tmp = parent;
					parent = node;
					node = tmp;
				}

				parent->color = BLACK;
				gparent->color = RED;
				root = RB_RotateLeft(gparent, root);
			}
		}
	}

	root->color = BLACK;

	return root;
}

RB_NODE *RB_SearchAuxiliary(int key, RB_NODE *root, RB_NODE **save)
{
	RB_NODE *node = root;
	RB_NODE *parent = NULL;
	int ret;

	while(node)
	{
		parent = node;
		ret = node->key - key;
		if(ret > 0)
			node = node->left;
		else if(ret < 0)
			node = node->right;
		else
			return node;
	}

	if(save)
		*save = parent;

	return NULL;
}

RB_NODE *RB_Search(int key, RB_NODE *root)
{
	return RB_SearchAuxiliary(key, root, NULL);
}

RB_NODE *RB_Insert(int key, int data, RB_NODE *root)
{
	RB_NODE *parent = NULL;
	RB_NODE *node = NULL;

	parent = NULL;
	if((node = RB_SearchAuxiliary(key, root, &parent)))
	{
		++(node->data);
		return root;
	}

	node = RB_CreateNode(key, data);
	node->parent = parent;

	if(parent)
	{
		if(parent->key > key)
			parent->left = node;
		else
			parent->right= node;
	}
	else
		root = node;

	return RB_Insert_Rebalance(node, root);
}

void InOrderTraverse(RB_NODE *node)
{
	if(NULL == node)
		return;
	else
	{
		InOrderTraverse(node->left);
		if(node->data > heap[1].data)
		{
			heap[1].data = node->data;
			heap[1].key = node->key;
			MIN_HEAPIFY(heap, heapSize, 1);
		}
		InOrderTraverse(node->right);
	}
}

void RB_Destory(RB_NODE *node)
{
	if(NULL == node)
		return;
	else
	{
		RB_Destory(node->left);
		RB_Destory(node->right);
		free(node);
		node = NULL;
	}
}



void MIN_HEAPIFY(RB_HEAP *A, const int &size, int i)
{
	int l = LEFT(i);
	int r = RIGHT(i);
	int smallest = i;

	if(l<=size && A[l].data < A[i].data)
		smallest = l;
	if(r<=size && A[r].data < A[smallest].data)
		smallest = r;

	if(smallest != i)
	{
		RB_HEAP tmp = A[i];
		A[i] = A[smallest];
		A[smallest] = tmp;
		MIN_HEAPIFY(A, size, smallest);
	}
}

void BUILD_MINHEAP(RB_HEAP *A, const int &size)
{
	for(int i=size/2 ; i>=1 ; --i)
		MIN_HEAPIFY(A, size, i;)
}
