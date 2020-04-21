//面试题27:二叉搜索树和双向链表
//采用中序遍历方式的递归实现
//根结点的左指针链接左子树的最大值
//根结点的有指针链接右子树的最小值


/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    void ConvertNode(TreeNode *pNode, TreeNode **pLastNode)
{
    if (pNode == NULL)
        return;
    TreeNode *pCur = pNode;
    if (pCur->left != NULL)
    {
        ConvertNode(pCur->left, pLastNode);//遍历左子树
    }
     //处理根节点
    pCur->left = *pLastNode;
    if (*pLastNode != NULL)
        (*pLastNode)->right = pCur;
    *pLastNode = pCur;
     //遍历右子树
    if (pCur->right != NULL)
    {
        ConvertNode(pCur->right, pLastNode);
    }
}

TreeNode* Convert(TreeNode* pRootOfTree)
{
    TreeNode *pLastNode = NULL;//指向双向链表的尾结点
    ConvertNode(pRootOfTree, &pLastNode);//二叉排序树转换成排序双向链表

    //取得双向链表的头指针
    TreeNode *pHead = pLastNode;
    while (pHead != NULL&&pHead->left != NULL)
    {
        pHead = pHead->left;
    }
    return pHead;
}
            
    
};
