//习题：合并两个有序数组

#include<iostream>
#include<cstring>
#define MAX_NUMBER 100
typedef int ElemType;

using namespace std;

void merge_arry(ElemType A1[], ElemType A2[]){
	int ca1=0, ca2=0;
	while(A1[ca1++] != -1);
	ca1--;
	while(A2[ca2++] != -1);
	ca2--;
	int new_ca1 = ca1+ca2;
	while(new_ca1--){
		if(ca1==0 || ca2==0)
			break;
		if(A2[ca2-1]>A1[ca1-1]){
			A1[new_ca1]=A2[--ca2];
			continue;
		}
		A1[new_ca1]=A1[--ca1];
	}
	while(ca2){
		A1[new_ca1--] = A2[--ca2];
	}
}

int main()
{
	ElemType A1[MAX_NUMBER];
	memset(A1,-1,MAX_NUMBER*sizeof(ElemType));
	ElemType A2[MAX_NUMBER];
	memset(A2,-1,MAX_NUMBER*sizeof(ElemType));
	for(int i=0;i<7;i++)
		cin>>A1[i];
	for(int k=0;k<5;k++)
		cin>>A2[k];
	merge_arry(A1,A2);
	int h=0;
	while(A1[h]!=-1){
		cout << A1[h] << " ";
		h++;
	}	
	return 0;
 } 
