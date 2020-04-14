//面试题5:从尾到头逆序打印链表，借助于栈进行操作



#include<stdio.h>
#include<stdlib.h>
#include<stack>
typedef struct node
{
	int data;
	struct node *next;
}*PNODE,NODE;
void insert(PNODE head, int newdata);
void print(PNODE head);
PNODE init();
PNODE FindKthToTail(PNODE head,unsigned int k);
void freeAllNode(PNODE head);
void PrintLinkInv_Ite(PNODE head){
	std::stack<PNODE> nodes;
	PNODE phead;
	phead=head->next;
	while(phead!=NULL){
		nodes.push(phead);
		phead=phead->next;
	} 
	while(!nodes.empty()){
		phead=nodes.top();
		printf("%d ", phead->data);
		nodes.pop();
	}
}

	
int main()
{
	unsigned int pos=6;
	PNODE head = init();    //接受init()的返回值, 即指向了temp
	for (int i = 0; i < 10;i++)
	 insert(head,i);
	print(head);
	PNODE result=FindKthToTail(head,pos);
	PrintLinkInv_Ite(head);
	prinf("\n"); 
	if(result!= NULL)
		printf("%d",result->data);
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
