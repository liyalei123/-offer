//面试题8:旋转数组的最小数字
//利用二分法的思想

#include<iostream>
using namespace std;
int MinInOrder(int* nums, int index1,int index2){
	int result=nums[index1];
	for(int i=index1;i<=index2;i++){
		if(result >= nums[i])
			result=nums[i];
	}
	return result;
}
int Min(int* nums, int length){
	if(nums==NULL || length<=0)//非法输入处理 
		throw "Invalid input.";
	int index1 = 0, index2 = length-1;
	int indexMid = index1;
	while(nums[index1] >= nums[index2]){
		if(index2-index1==1){
			indexMid = index2;
			break;
		}
		indexMid=(index1+index2)/2;
		if(nums[index1]==nums[index2] && nums[indexMid]==nums[index1]){
			return MinInOrder(nums,index1,index2);
		}
		if(nums[indexMid]>=nums[index1]){
			index1=indexMid;
		}else if(nums[indexMid]<=nums[index2]){
			index2=indexMid;
		}
			
	}
	return nums[indexMid];
} 

int main()
{
	int nums1[]={3,4,5,1,2};
	int a=Min(nums1,5);
	cout << a << endl;

	int nums2[]={0,1,2,3,4};
	int b=Min(nums2,5);
	cout << b << endl;	
	
	int nums3[]={1,0,1,1,1};
	int c=Min(nums3,5);
	cout << c << endl;
	
}
