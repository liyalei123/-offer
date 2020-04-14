//用两个队列实现栈



#include<iostream>
#include<queue>
using namespace std;
template<typename T> class MyStack{
	private:
		queue<T> queue1;
		queue<T> queue2;
	public:
		MyStack(void)=default;
		~MyStack(void)=default;
		T deletefront();
		void addtail(const T& Value);
}; 
template<typename T> void MyStack<T>:: addtail(const T& Value){
	if(!queue1.empty()){
		queue1.push(Value);
	}
	else{
		queue2.push(Value);
	}
}
template<typename T> T MyStack<T>::deletefront(){
	T result;
	if(!queue1.empty()){
		int num=queue1.size();
		while(num > 1){
			queue2.push(queue1.front());
			queue1.pop();
			num--;
		}
		result=queue1.front();
		queue1.pop();
	}
	else{
		int num2=queue2.size();
		while(num2>1){
			queue1.push(queue2.front());
			queue2.pop();
			num2--;
		}
		result=queue2.front();
		queue2.pop();
	}
	return result;
}
int main()
{
	MyStack<int> S;
	S.addtail(1);
	S.addtail(2);
	S.addtail(3);
	int i=S.deletefront();
	printf("%d",i);	
	return 0;
}
