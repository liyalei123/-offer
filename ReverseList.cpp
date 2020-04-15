//面试题16:逆序链表


#include<stdio.h>
#include<stdlib.h>
#include<iostream> 
using namespace std;
typedef struct node
{
	int data;
	struct node *next;
}*PNODE,NODE;
void insert(PNODE head, int newdata);
void print(PNODE head);
void print1(PNODE head);
PNODE init();
PNODE FindKthToTail(PNODE head,unsigned int k);
void freeAllNode(PNODE head);
PNODE MidInListNode(PNODE head); 
bool IsLoop(PNODE head);
PNODE ReverseList(PNODE head);
int main()
{
	unsigned int pos=6;
	PNODE head = init();    //接受init()的返回值, 即指向了temp
	for (int i = 0; i < 10;i++)
	 insert(head,i);
	print(head);
	PNODE result=FindKthToTail(head,pos);
	if(result!= NULL)
		printf("%d\n",result->data);
	PNODE Mid=MidInListNode(head);
	printf("%d\n",Mid->data);
	cout << IsLoop(head) << endl;
	PNODE R = ReverseList(head);
	print1(R);
    freeAllNode(head);
	return 0;
}
PNODE init()
{
	PNODE temp = (PNODE)malloc(sizeof(NODE));
	temp->next = NULL;
	return temp;
}
void insert(PNODE head,int newdata)
{
 
	PNODE temp=(PNODE)malloc(sizeof(struct node));
	temp->data = newdata;
	//头插
	temp->next = head->next;
	head ->next= temp;
#if 0
	//尾插
	PNODE p = (PNODE)malloc(sizeof(NODE));
	p = head;
	while (p->next != NULL) p = p->next;
	p->next = temp;
	temp->next = NULL;
#endif
}
void print(PNODE head)
{
	PNODE temp=head->next;
	while (temp!=NULL)
	{
		printf("%d->", temp->data);
		temp = temp->next;
	}
	printf("NULL\n");
	
}
void print1(PNODE head)
{
	PNODE temp=head;
	while (temp!=NULL)
	{
		printf("%d->", temp->data);
		temp = temp->next;
	}
	printf("NULL\n");
	
}
void freeAllNode(PNODE head)
{
	PNODE p = head,temp;
	while (p != NULL)
	{
		temp = p->next;
		free(p);
		p = temp;
	}

}
PNODE FindKthToTail(PNODE head,unsigned int k){
	if(!head)
		return NULL;
	PNODE fast=head,slow=head;
	while(k--){
		if(fast==NULL)      //判断链表长度是否小于k 
			return NULL;
		fast = fast->next;
	}
	while(fast != NULL){
		fast=fast->next;
		slow=slow->next;
	}
	return slow;
}

PNODE MidInListNode(PNODE head){
	PNODE fast,slow;
	fast = head;
	slow = head;
	while(fast->next!=NULL && fast->next->next!=NULL && slow->next!=NULL){
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}
bool IsLoop(PNODE head){
	if(head==NULL||head->next == NULL)
		return false;
	PNODE fast, slow;
	fast = head;
	slow = head;
	while(1){
		if(fast->next == NULL)
			return false;
		if(fast->next != NULL && fast->next->next != NULL)
		{
			fast = fast->next->next;
			slow = slow->next;
			
		}else{
			fast = fast->next;
		}
		if(fast == slow)
			return true;
	}
	
}
PNODE ReverseList(PNODE head){
	PNODE pPrev = NULL;
	PNODE pReverseNode = NULL;
	PNODE pNode = head->next;
	PNODE pNext = NULL;
	while(pNode != NULL){
		pNext=pNode->next;
		if(pNext == NULL)
			pReverseNode = pNode;
		pNode->next=pPrev;
		pPrev = pNode;
		pNode = pNext;
	}
	return pReverseNode;
	
}
