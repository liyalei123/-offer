//面试题6:重建二叉树
//由先序遍历和中序遍历构建二叉树


#include<iostream>
#include<exception> 

using namespace std;

struct BinaryTreeNode{//二叉树的结构 
	int data;
	BinaryTreeNode* pLChild;
	BinaryTreeNode* pRChild;
}; 
BinaryTreeNode* PreOrderInOrderToTreeCore(int* startpreOrder,int* endpreOrder,int* startinOrder,int* endinOrder)
{
	int rootValue = startpreOrder[0];
	BinaryTreeNode* root=new BinaryTreeNode();
	root->data=rootValue;
	root->pLChild=root->pRChild=NULL;
	if(startpreOrder == endpreOrder){
		//只有一个节点的情况
		if(startinOrder == endinOrder && *startpreOrder == *endpreOrder)
			return root;
		else 
			throw "Invalid input."; 
	}
	int* rootInOrder = startinOrder;
	while(rootInOrder <= endinOrder&&*rootInOrder!=rootValue)
		++rootInOrder;
	if(rootInOrder==endinOrder&&*rootInOrder!=rootValue)
		throw "Invaild input.";	
	int leftLength=rootInOrder - startinOrder;
	int* leftPreorderEnd = startpreOrder+leftLength;
	if(leftLength>0){
		//构建左子树 
		root->pLChild=PreOrderInOrderToTreeCore(startpreOrder+1,leftPreorderEnd,startinOrder,rootInOrder-1);
	}
	if(leftLength < endpreOrder-startpreOrder){
		root->pRChild=PreOrderInOrderToTreeCore(leftPreorderEnd+1,endpreOrder,rootInOrder+1,endinOrder);
	}
	 return root;
}
BinaryTreeNode* PreOrderInOrderToTree(int* preOrder, int* inOrder, int Length)
{
	if(preOrder==NULL ||inOrder==NULL||Length <=0)
		return NULL;
	return PreOrderInOrderToTreeCore(preOrder,preOrder+Length-1,inOrder,inOrder+Length-1);
}

int main()
{
	int a[]={1,2,4,7,3,5,6,8};
	int b[]={4,7,2,1,5,3,8,6};
	int length=8;
	BinaryTreeNode* root=PreOrderInOrderToTree(a,b,length);
	printf("%d",root->data);
} 
