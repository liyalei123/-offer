//面试题21:包含min函数的栈

class Solution {//借助两个栈，一个栈用来保存数据
    //另一个栈用来保存最小值
public:
    stack<int> stackData, stackMin;
   
    
    void push(int value) {
    	stackData.push(value);
       // if(stackMin.empty())
       //     stackMin.push(value);
       // else if(stackMin.top()>=value)
       //     stackMin.push(value);
    	if(stackMin.empty()||stackMin.top() > value)
    		stackMin.push(value);
    	else
    		stackMin.push(stackMin.top());
        
    }
    void pop() {
    	stackData.pop();
    	stackMin.pop();
        
    }
    int top() {
    	return stackData.top();
        
    }
    int min() {
        return stackMin.top();
    }
};
