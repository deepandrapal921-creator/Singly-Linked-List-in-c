#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* createNode(int value){
    struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next=NULL;
    return newNode;
}
void insertBeginning(struct Node**head,int value){
    struct Node*newNode=createNode(value);
    newNode->next= *head;
    *head=newNode;
}
void insertEnd(struct Node**head,int value){
    struct Node*newNode=createNode(value);
    if(*head==NULL){
        *head=newNode;
        return;
    }
    struct Node* temp = *head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
}

void insertposition(struct Node**head,int value,int pos){
    if(pos==1){
        insertBeginning(head,value);
        return;
    }
struct Node*newNode=createNode(value);
struct Node* temp=*head;
int i;
  for(int i = 1; i<pos - 1 && temp != NULL; i++){
    temp=temp->next;
  }
  if(temp==NULL){
    printf("position out of range!\n");
    free(newNode);
  }
  else{
    newNode->next=temp->next;
    temp->next=newNode;
  }
}
void display(struct Node* head){
    struct Node* temp = head;
    while (temp != NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}
int main(){
    struct Node* head=NULL;
    insertBeginning(&head,10);
    insertBeginning(&head,20);
    insertEnd(&head,30);
    display(head);
    return 0;
}
