#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *link;
};
struct Node *head=NULL, *loop=NULL;

struct Node* createNode(int data){
    struct Node* new=(struct Node*)malloc(sizeof(struct Node));
    new->data=data;
    new->link=NULL;
    return new;
}

void createLL(int data){
    struct Node *current=head;
    struct Node *new=createNode(data);
    if(head==NULL){
        head=new;
        return;
    }
    while(current->link!=NULL){
        current=current->link;
    }
    current->link=new;
    return;
}


void createLoop(int data){
    if(loop==NULL){
        loopHead();
    }
    struct Node* new=createNode(data);
    struct Node *current=loop;
    while(current->link!=loop){
        current=current->link;
    }
    current->link=new;
    new->link=loop;
}


void check(){
    struct Node *slow,*fast;
    slow=fast=head;
    while(fast && fast->link){
        slow=slow->link;
        fast=fast->link->link;
        if(slow==fast){
            printf("loop is there");
            return;
        }
    }
    printf("loop absent");
    return;
}

void display() {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->link;
    }
    printf("NULL\n");
}

int main(){
    int data,ch;
    while(1){
        printf("\n1.linear 2.loop: 3.check");scanf("%d",&ch);
        if(ch==1){
            printf("input data: ");scanf("%d",&data);
            createLL(data);
        }
        else if(ch==2){
            printf("input data: ");scanf("%d",&data);
            createLoop(data);            
        }
        else{
            check();
        }
    }
    return 0;
}
