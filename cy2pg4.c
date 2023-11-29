//queue using linked list
#include<stdio.h>
#include<stdlib.h>

struct Queue{
    int val;
    struct Queue *link;
};
struct Queue *queue=NULL;
//enqueue operation
void enqueue(int elt){
    struct Queue *new=(struct Queue *)malloc(sizeof(struct Queue));
    if(new==NULL){
        printf("cannot allocate memory");
        exit(0);
    }
    new->val=elt;
    new->link=queue;
    queue=new;
}

void dequeue(){
    struct Queue *current=queue,*temp=NULL;
    if(queue==NULL){
        printf("queue is empty");
        exit(0);
    }
    while(current->link!=NULL){
        temp=current;
        current=current->link;
    }
    if(temp==NULL){
        printf("deleted elt: %d",current->val);
        free(current);
        queue=NULL;
    }
    else{
        printf("deleted elt: %d",current->val);
        temp->link=NULL;
        free(current);
    }
}

void display(){
    struct Queue *current=queue;
    printf("\nqueue: ");
    if(queue==NULL){
        printf("empty");
        return;
    }
    while(current!=NULL){
        printf("%d ",current->val);
        current=current->link;
    }
}

int main(){
    int ch,elt;
    while(1){
        printf("\n1.enqueue 2.dequeue 3.display 4.exit..");scanf("%d",&ch);
        if(ch==1){
            printf("elt: ");scanf("%d",&elt);
            enqueue(elt);
            display();
        }
        else if(ch==2){
            dequeue();
            display();
        }
        else if(ch==3){
            display();
        }
        else return -1;
    }
}