//求链表中的倒数第k个结点
//思路；设立两个指针fast和slow，两者均指向head
//先让fast走k-1步，然后fast和slow一起走，当fast指向NULL时
//slow指向第k个结点



#include<stdio.h>
#include<stdlib.h>
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
int main()
{
	unsigned int pos=6;
	PNODE head = init();    //接受init()的返回值, 即指向了temp
	for (int i = 0; i < 10;i++)
	 insert(head,i);
	print(head);
	PNODE result=FindKthToTail(head,pos);
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
