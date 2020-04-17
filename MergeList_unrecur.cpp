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
PNODE MergeList(PNODE head1, PNODE head2);
PNODE MergeList_nurecur(PNODE head1, PNODE head2);
int main()
{
	unsigned int pos=6;
	PNODE head = init(); 
	PNODE head2 = init();   //接受init()的返回值, 即指向了temp
	for (int i = 0; i < 10;i++)
	 insert(head,i);
	for(int i = 0; i< 10; i++)
		insert(head2,2*i);
	print(head);
	print1(head2);
	PNODE mergeHead = MergeList(head->next,head2->next);
	print(mergeHead);
	PNODE mergeHead2 = MergeList_nurecur(head->next, head2->next);
	print1(mergeHead2);
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
PNODE MergeList(PNODE head1, PNODE head2){
	if(head1 == NULL)
		return head2;
	else if(head2 == NULL)
		return head1;
	PNODE mergeHead=NULL;
	PNODE phead1 = head1;
	PNODE phead2 = head2;
	if(phead1->data < phead2->data)
	{
		mergeHead= phead1;
		mergeHead->next = MergeList(phead1->next,phead2);
	}else
	{
		mergeHead = phead2;
		mergeHead->next = MergeList(phead1,phead2->next);
	}
	return mergeHead;
} 
PNODE MergeList_nurecur(PNODE head1, PNODE head2){
	if(head1 == NULL)
		return head2;
	else if(head2 == NULL)
		return head1;
	
	PNODE mergeList=NULL;
	PNODE current = mergeList;
	while(head1!= NULL && head2!= NULL){
		if(head1->data < head2->data){
			current->next = head1;
			head1=head1->next;
		}
		else{
			current->next = head2;
			head2 = head2->next;
		}
		current=current->next;
	}
	if(head1 == NULL)
		current->next = head2;
	if(head2 == NULL)
		current->next = head1;
	return mergeList->next;
} 
