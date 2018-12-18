#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int data;
    struct Node* next;
}Node;
typedef struct List{
    struct Node *head;
    struct Node *cur;
    struct Node *befor;
    int numOfData;
    int(*comp)(int,int);
}List;
void ListInit(List*plist);
void LInsert(List*plist, int data);

void LFirst(List * plist,int* pdata);
void LNext(List * plist,int* pdata);

int LRemove(List * plist);
int LCount(List * plist);

int main(int argc, char const *argv[])
{
    return 0;
}

void ListInit(List* plist) {
    plist->head = (Node*)malloc(sizeof(Node));
    plist->head->next = NULL;
    plist->comp = NULL;
    plist->numOfData = 0;
}
void LInsert(List*plist, int data){

}

void FInsert(List*plist, int data){
    Node *newNode=(Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next =

}