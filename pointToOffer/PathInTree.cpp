/*
 * function: find a path, the sum of the key equal to the given number
 *
 * author:	dongbeibei
 * time:	2013/8/28
 */

struct BinaryTreeNode
{
	int				m_nValue;
	BinaryTreeNode	*m_pLeft;
	BinaryTreeNode	*m_pRight;
};

void FindPath(BinaryTreeNode *pRoot, int exceptSum)
{
	if(pRoot == NULL)
		return;

	std::vector<BinaryTreeNode*> path;
	int currentSum = 0;
	helper(pRoot, path, exceptSum, currentSum);
}

void helper(BinaryTreeNode *pRoot, std::vector<BinaryTreeNode*>& path, int exceptSum, int currentSum)
{
	currentSum += pRoot->m_nValue;
	path.push_back(pRoot);

	bool isLeaf = (pRoot->m_pLeft==NULL)&&(pRoot->m_pRight==NULL);
	if(currentSum==exceptSum && isLeaf)
	{
		cout<<"A path is found:\t";
		std::vector<BinaryTreeNode*>::iterator iter = path.begin(), rear = path.end(), next;
		for( ; iter!=rear ; ++iter)
		{
			cout<<(*iter)->m_nValue;
			next = iter + 1;
			if(next != rear)
			{
				if((*iter)->m_pLeft == (*next))
					cout<<" (left) ";
				else
					cout<<" (right) ";
			}
		}
		cout<<endl;
	}

	if(pRoot->m_pLeft != NULL)
		helper(pRoot->m_pLeft, path, exceptSum, currentSum);
	if(pRoot->m_pRight != NULL)
		helper(pRoot->m_pRight, path, exceptSum, currentSum);

	currentSum -= pRoot->m_nValue;
	path.pop_back();
}
