//queue
#include<stdio.h>
#include<stdlib.h>

int queue[100]={0};
int front=-1,rear=-1,n;

void enqueue(int data){
    if(rear==n-1){printf("queue :full");exit(0);}
    if(front==-1) front=0;
    rear++;
    queue[rear]=data;
}
void dequeue(){
    if(front==-1){printf("queue: empty");exit(0);}
    printf("deleted elt: %d\n",queue[front]);
    if(front==rear) front=rear=-1;
    else front++;
}
void display(){
    printf("queue: ");
    if(front==-1){printf("empty\n");return;}
    for(int i=front;i<=rear;i++){
        printf("%d  ",queue[i]);
    }
    printf("\n");
}

void main(){
    int ch,data;
    printf("input n: ");scanf("%d",&n);
    while(1){
        printf("1.enqueue 2.dequeue 3.display 4.exit: ");scanf("%d",&ch);
        switch (ch){
        case 1: printf("data: ");scanf("%d",&data);
                enqueue(data);display();
                break;
        case 2: dequeue();display();break;
        case 3: display();break;
        default: return;
        }
    }
}