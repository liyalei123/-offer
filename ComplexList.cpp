//面试题26:复杂链表的复制
//分三步走：第一步在每一个结点后面复制新结点
//第二步：复制指针
//第三步：重新链接链表




/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    void CloneNodes(RandomListNode* pHead){
        RandomListNode* pNode = pHead;
        while(pNode!= NULL){
            RandomListNode* CloneNode = NULL;
            CloneNode->label = pNode->label;
            CloneNode->next = pNode->next;
            CloneNode->random = NULL;
            
            pNode->next = CloneNode;
            pNode = CloneNode->next;
        }
    }
    void CloneRandom(RandomListNode* pHead){
        RandomListNode* pNode = pHead;
        while(pNode!=NULL)
        {
            RandomListNode* CloneNode = pNode->next;
            if(pNode->random!=NULL)
                CloneNode->random = pNode->random->next;
            pNode = CloneNode->next;
        }
    }
    RandomListNode* ReconnextNodes(RandomListNode* pHead){
        RandomListNode* CloneHead = NULL;
        RandomListNode* CloneNode = NULL;
        RandomListNode* pNode = pHead;
        if(pNode != NULL)
        {
            CloneHead = CloneNode = pNode->next;
            pNode->next = CloneNode->next;
            pNode = pNode->next;
        }
        while(pNode!=NULL)
        {
            CloneNode->next = pNode->next;
            CloneNode = CloneNode->next;
            pNode->next = CloneNode->next;
            pNode = pNode->next;
        }
        return CloneHead;
    }
    RandomListNode* Clone(RandomListNode* pHead)
    {
        CloneNodes(pHead);
        CloneRandom(pHead);
        return ReconnextNodes(pHead);
    }
};
