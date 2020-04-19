//面试题24:二叉搜索树的后序遍历序列
//左子树比根结点小，右子树比根结点大
//首先找到根结点，然后找左子树和右子树
//递归判断左右子树是否是一个二叉搜索树


class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if(sequence.empty())
            return false;
        int root = sequence[sequence.size()-1];
        
        //找到左子树，左子树的结点均比根结点小
        vector<int> leftsequence;
        int i = 0;
        for(;i < sequence.size()-1;i++){
            if(sequence[i] < root)
                leftsequence.push_back(sequence[i]);
            else
                break;
        }
        
        //找到右子树，右子树的结点均比根结点大
        vector<int> rightsequence;
        int j;
        for(j=i;j< sequence.size()-1;j++){
            if(sequence[j]>root)
                rightsequence.push_back(sequence[j]);
            else
                return false;
        }
        
        int left = true;
        if(!leftsequence.empty())
            left = VerifySquenceOfBST(leftsequence);
        
        int right=true;
        if(!rightsequence.empty())
            right = VerifySquenceOfBST(rightsequence);
        
        return left&&right;
            
            
            
    }
};
