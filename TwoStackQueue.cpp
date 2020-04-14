//面试题7:用两个栈来实现队列


#include<iostream>
#include<stack>
using namespace std;

template<typename T> class MyQueue{
	private:
		stack<T> stack1;
		stack<T> stack2;
	public:
		MyQueue(void)=default;
		~MyQueue(void)=default;
		void appendTail(const T& Value);
		T deleteHead(); 
};

template<typename T> void MyQueue<T>::appendTail(const T& Value){
	stack1.push(Value);
} 
template<typename T> T MyQueue<T>::deleteHead(){
	if(stack2.size()<=0)
	{
		while(stack1.size()>0){
			T& data=stack1.top();
			stack1.pop();
			stack2.push(data); 
		}
	}
	if(stack2.size()==0)
		throw "queue is empty";
	T head = stack2.top();
	stack2.pop();
	return head;
}
int main(){
	MyQueue<int> Q;
	Q.appendTail(1);
	Q.appendTail(2);
	Q.appendTail(3);
	auto i = Q.deleteHead();
	printf("%d",i);
	Q.deleteHead();
	Q.deleteHead();
	return 0;
}

