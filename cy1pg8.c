//priority queue using linked list
#include<stdio.h>
#include<stdlib.h>

struct priq{
    int val;
    int pri;
    struct priq *next;
    struct priq *prev;
};
struct priq *pq=NULL;

void enqueue(int val,int pri){
    struct priq *new=(struct priq*)malloc(sizeof(struct priq));
    if(new==NULL){
        printf("memeory overflow");exit(0);
    }
    struct priq *current=pq,*temp=NULL;
    new->next=NULL;new->prev=NULL;new->pri=pri;new->val=val;
    if(pq==NULL){
        pq=new;
        return;
    }
    while(current!=NULL && pri<current->pri){
        temp=current;
        current=current->next;
    }
    if(current==NULL){
        temp->next=new;
        new->prev=temp;
    }
    else{
        if(temp==NULL){
            new->next=current;
            current->prev=new;
            pq=new;
        }
        else{
            new->prev=current->prev;
            new->next=current;
            temp->next=new;
            current->prev=new;
        }
    }
}
void dequeue(){
    struct priq *current=pq;
    if(pq==NULL){
        printf("queue is empty");
        exit(0);
    }
    printf("deleted: %d | %d\n",current->val,current->pri);
    if(current->next==NULL){
        free(current);
        pq=NULL;
    }
    else{
        pq=current->next;
        current->next=NULL;
        pq->prev=NULL;
        free(current);
    }
}
void display(){
    struct priq *current=pq;
    printf("queue: \n");
    if(pq==NULL){
        printf("empty");return;
    }
    while(current!=NULL){
        printf("%d | %d\n",current->val,current->pri);
        current=current->next;
    }
}

void main(){
    int ch,data,pri;
    //printf("input n: ");scanf("%d",&n);
    while(1){
        printf("1.enqueue 2.dequeue 3.display 4.exit: ");scanf("%d",&ch);
        switch (ch){
        case 1: printf("val & pri: ");scanf("%d %d",&data,&pri);
                enqueue(data,pri);display();
                break;
        case 2: dequeue();display();break;
        case 3: display();break;
        default: return;
        }
    }
}