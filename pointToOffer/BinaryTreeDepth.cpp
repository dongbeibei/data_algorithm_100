/*
 * function: count the depth of binary tree, identify a binary tree is balanced or not
 *
 * author:	dongbeibei
 * time:	2013/8/29
 */


struct BinaryTreeNode
{
	int				m_nValue;
	BinaryTreeNode	*m_pLeft;
	BinaryTreeNode	*m_pRight;
};

int DepthOfBinaryTree(BinaryTreeNode *pRoot)
{
	if(pRoot == NULL)
		return 0;

	int left = DepthOfBinaryTree(pRoot->m_pLeft);
	int right = DepthOfBinaryTree(pRoot->m_pRight);

	return ((left>right)? (left+1) : (right+1));
}

bool IsBalanced(BinaryTreeNode *pRoot, int *pDepth)
{
	if(pRoot == NULL)
	{
		*pDepth = 0;
		return true;
	}

	int left, right;
	if(IsBalanced(pRoot->m_pLeft, &left) && IsBalanced(pRoot->m_pRight, &right))
	{
		int diff = left - right;
		if(diff<=1 && diff>=-1)
		{
			*pDepth = 1 + (left>right)?left:right;
			return true;
		}
	}

	return false;
}

bool IsBalanced(BinaryTreeNode *pRoot)
{
	int depth = 0;
	return IsBalanced(pRoot, &depth);
}
