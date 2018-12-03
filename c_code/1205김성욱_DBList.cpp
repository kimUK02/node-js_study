#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct _node
{
    int data;
    _node * next;
    _node * prev;
}Node;

typedef struct _DLinkedList
{
    Node * head;
    Node * cur;
    int numOfData;
}List;

void ListInit(List * plist);
void LInsert(List * plist, int data);

int LFirst(List *plist,int * pdata);
int LNext(List *plist,int * pdata);
int LPrevious(List *plist,int * pdata);
int LCount(List* plist);

int main(int argc, char const *argv[])
{
    List myList;
    int curNum = 0;
    ListInit(&myList);
    for(int i = 8;i>0;i--){
        LInsert(&myList,i);
    }

    LFirst(&myList,&curNum);
    printf("%d ",curNum);
    while(LNext(&myList,&curNum))
    {
        printf("%d ",curNum);
    }
    while(LPrevious(&myList,&curNum))
    {
        printf("%d ",curNum);
    }
    printf("\n");



    return 0;
}
void ListInit(List * plist)
{
    plist->head = NULL;
    plist->numOfData = 0;
}
void LInsert(List * plist, int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    newNode->next = plist->head;
    if(plist->head != NULL) plist->head->prev = newNode;
    newNode->prev = NULL;
    plist->head = newNode;
    (plist->numOfData)++;
}

int LFirst(List *plist,int * pdata)
{
    if(plist->head == NULL) return FALSE;
    plist->cur = plist->head;
    *pdata = plist->cur->data;

    return TRUE;
}

int LNext(List * plist, int * pdata)
{
    if(plist->cur->next == NULL) return FALSE;
    plist->cur = plist->cur->next;
    *pdata = plist->cur->data;
    
    return TRUE;
}

int LPrevious(List *plist, int * pdata)
{
    if(plist->cur->prev == NULL) return FALSE;
    plist->cur = plist->cur->prev;
    *pdata = plist->cur->data;
    return TRUE;
}

int LCount(List * plist)
{
    return plist->numOfData;
}


