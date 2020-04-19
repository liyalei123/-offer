//面试题21:栈的压入和弹出操作
//思路：用一个vector来模拟栈，当pushV.size()不是零的时候
//开始循环，然后将pushV压入栈，当vector的尾和popV相同时我们
//弹出popV，最后如果vector为空，则判断成功
class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if(pushV.size()==0)
            return false;
        vector<int> stack;
        for(int i=0,j=0;i<pushV.size();){
            stack.push_back(pushV[i++]);
            while(j<popV.size() && popV[j]==stack.back()){
                stack.pop_back();
                j++;
            }
        }
        return stack.empty();
    }
};

