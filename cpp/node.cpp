#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int item;
    struct Node* next;
}Node;

void PrintList(Node *ptr);
Node* insertSort(Node * ptr, int dat);

int main(int argc, char const *argv[])
{
    int array[5] = {32, 98, 56, 73, 85};
    int i;
    Node* Head = NULL;

    for(int i = 0; i < 5; i++){
        Head = insertSort(Head, array[i]);
        PrintList(Head);
    }
    return 0;
}
Node* insertSort(Node*ptr, int data){
 
    Node *New = (Node*)malloc(sizeof(Node*));
    Node *temp = (Node*)malloc(sizeof(Node*));
    Node *prev = (Node*)malloc(sizeof(Node*));
    New->item = data;
    New->next = NULL;
    if(ptr == NULL){
        ptr=New;
    }else{
        if(New->item < ptr->item){
            New->next = ptr;
            ptr = New;
        
        }else{
            temp = ptr;
            while(temp != NULL && New->item > temp->item){
                prev = temp;
                temp = temp->next;
            }
            New->next = prev->next;
            prev->next = New;
        }
    }
    return ptr;
}

void PrintList(Node*ptr){
    Node* curr = ptr;  
    while(curr != NULL){
        printf("%d ",curr->item);
        curr= curr->next;
    }
    printf("\n");
}