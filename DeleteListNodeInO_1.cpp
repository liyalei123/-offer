//在O（1）时间内删除链表中的结点
//必须要知道要删除的结点
//考虑删除结点不是尾结点，是尾结点和链表只有一个结点的情况
#include<cstdlib>
typedef struct ListNode{
	int m_Value;
	ListNode* m_Next;
}*PListNode, ListNode;

void DeleteListNodeO_1(PListNode list, PListNode node){
	if(!list ||!node)
		return;
	if(list->m_Next!=NULL){//要删除的节点不是尾节点 
		PListNode  pNext=node->m_Next;
		node->m_Value=pNext->m_Value;
		node->m_Next=pNext->m_Next;
		delete pNext;
		pNext=NULL;
	}else if(list==node){
		delete node;
		node=NULL;
		list=NULL;
	}else{
		ListNode* pNode = list;
		while(pNode->m_Next != node){
			pNode = pNode->m_Next;
		}
		pNode->m_Next=NULL;
		delete node;
		node=NULL;
	}
}

