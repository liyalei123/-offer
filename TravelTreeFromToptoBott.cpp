//面试题23:二叉树的层序遍历，从上到下打印二叉树
//思路：借助于队列。先将树的根结点入队，如果左右结点非空
//分别将左右结点入队




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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> Nums;
        if(root == NULL)
            return Nums;
        deque<TreeNode*> Qtemp;
        Qtemp.push_back(root);
        while(!Qtemp.empty()){
            TreeNode* pNode=NULL;
            pNode = Qtemp.front();
            Nums.push_back(pNode->val);
            Qtemp.pop_front();
            if(pNode->left!=NULL)
                Qtemp.push_back(pNode->left);
            if(pNode->right!=NULL)
                Qtemp.push_back(pNode->right);
        }
        return Nums;
    }
};
