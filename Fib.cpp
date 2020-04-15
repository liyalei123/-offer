//面试题9:斐波那契数列

#include<iostream>
using namespace std;
int Fib1(unsigned int n){
	if(n==0)
		return 0;
	if(n==1)
		return 1;
	if(n > 1)
		return Fib1(n-1)+Fib1(n-2);
}
int Fib2(unsigned int n){
	int result[2]={0,1};
	if(n <= 1)
		return result[n];
	else{
		long long one = 1;
		long long two = 0;
		long long FibN=0;
		for(int i=2;i<=n;i++){
			FibN=one + two;
			two = one;
			one = FibN;
			
		}
		return FibN;
	}
}
int main()
{
	cout << Fib1(3) << endl;
	cout << Fib2(3) << endl;
	return 0;
	
}
