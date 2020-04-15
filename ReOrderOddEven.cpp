//面试题14:调整数组顺序使得奇数在偶数前面
//利用二分法的思想，设置两个指针


#include<iostream>
using namespace std;
void ReOrderOddEven(int *Nums, int Length){
	if(Nums==NULL || Length ==0)
		return;
	int *pHead = Nums;
	int *pEnd=Nums+Length-1; 
	while(pHead < pEnd){
		while(pHead < pEnd && ((*pHead)&0x1) != 0)
			pHead++;
		while(pHead < pEnd && ((*pEnd)&0x1)== 0)
			pEnd--;
		if(pHead < pEnd){
			int temp = *pHead;
			*pHead = *pEnd;
			*pEnd = temp; 
		}
	}
} 
int main()
{
	int Nums[]={1,2,3,4,5};
	ReOrderOddEven(Nums,5);
	for(int i=0;i<5;i++)
		printf("%d ",Nums[i]);
	return 0;
}
