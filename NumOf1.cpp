//面试题11:二进制中1的个数
//判断一个数是不是2的乘方
//判断一个数变成另一个数需要更改几位

#include<iostream>
using namespace std;
int numOf1(int n){
	int count=0;
	unsigned int flag = 1;
	while(flag){
		if(flag & n)
			count++;
		flag=flag<<1;
	}
	return count;
}
int numOf1_m(int n){
	int count=0;
	while(n){
		count++;
		n=(n-1)&n;
	}
	return count;
}
bool Squareof2(int n){
	if(n & (n-1))
		return false;
	else
		return true;
}
int changeNum(int m, int n){
	numOf1_m(m|n);
}

int main()
{
	cout << numOf1(3) << endl;
	cout << numOf1_m(3) << endl;
	cout<< Squareof2(5) << endl;
	cout << changeNum(3,4) << endl;	
	return 0;
}
