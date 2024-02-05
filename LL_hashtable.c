#include<stdio.h>
#include<stdlib.h>

#define SIZE 7

struct Node{
    int data;
    struct Node *next;
};
struct Node *head=NULL;

struct ht{
    struct Node *link;
};
struct ht hash[7];

struct Node* createNode(int data){
    struct Node* new=(struct Node*)malloc(sizeof(struct Node));
    new->data=data;
    new->next=NULL;
    return new;
}

void createLL(int data){
    struct Node *current=head;
    struct Node *new=createNode(data);
    if(head==NULL){
        head=new;
        return;
    }
    while(current->next!=NULL){
        current=current->next;
    }
    current->next=new;
    return;
}

int hashFunction(int data){
    int val=data % SIZE;
    return val;
}

void insertHT(){
    int index;
    struct Node *current=head;
    if(head==NULL){
        printf("ll is empty");
        return;
    }
    for(int i=0;i<SIZE;i++){
        hash[i].link=NULL;
    }
    while(current!=NULL){
        struct Node *new=createNode(current->data);
        index=hashFunction(current->data);
        new->next=hash[index].link;
        hash[index].link=new;
        current=current->next;
    }
}

void displayHashTable(struct ht* hashTable) {
    for (int i = 0; i < SIZE; i++) {
        printf("Bucket %d: ", i);
        struct Node* current = hashTable[i].link;
        while (current != NULL) {
            printf("%d -> ", current->data);
            current = current->next;
        }
        printf("NULL\n");
    }
}
void displayLL() {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main(){
    int data,ch;
    while(1){
        printf("\n1.linear 2.convert :");scanf("%d",&ch);
        if(ch==1){
            printf("input data: ");scanf("%d",&data);
            createLL(data);
            displayLL();
        }
        else if(ch==2){
            printf("hash_table: \n");
            insertHT();   
            displayHashTable(hash);
        }
        else{
            //check();
        }
    }
    return 0;
}