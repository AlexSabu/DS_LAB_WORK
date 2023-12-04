//double ended queue
#include<stdio.h>
#include<stdlib.h>

int deque[100]={0};
int front=-1,rear=-1,n;

void f_enqueue(int data){
    if(front==(rear+1)%n){printf("queue: full");exit(0);}
    if(front==-1) rear=front=0;
    else if(front==0) front=n-1;
    else front--;
    deque[front]=data;
}
void r_enqueue(int data){
    if(front==(rear+1)%n){printf("queue: full");exit(0);}
    if(rear==-1) rear=front=0;
    else if(rear==n-1) rear=0;
    else rear++;
    deque[rear]=data;
}
void f_dequeue(){
    if(front==-1){printf("queue: empty");exit(0);}
    printf("deleted elt: %d\n",deque[front]);
    if(front==rear) front=rear=-1;
    else if(front==n-1) front=0;
    else front++;
}
void r_dequeue(){
    if(rear==-1){printf("queue: empty");exit(0);}
    printf("deleted elt: %d\n",deque[rear]);
    if(front==rear) front=rear=-1;
    else if(rear==0) rear=n-1;
    else rear--;   
}
void display(){
    printf("queue :");
    if(front==-1) {printf(" empty\n");return;}
    int i=front;
    while(i!=rear){
        printf("%d  ",deque[i]);
        i=(i+1)%n;
    }
    printf("%d\n",deque[rear]);
}

void main(){
    int ch,data;
    printf("input n: ");scanf("%d",&n);
    while(1){
        printf("1.f_enqueue 2.r_enqueue 3.f_dequeue 4.r_dequeue 5.display 6.exit: ");scanf("%d",&ch);
        switch (ch){
        case 1: printf("data: ");scanf("%d",&data);
                f_enqueue(data);display();
                break;
        case 2: printf("data: ");scanf("%d",&data);
                r_enqueue(data);display();
                break;
        case 3: f_dequeue();display();break;
        case 4: r_dequeue();display();break;
        case 5: display();break;
        default: return;
        }
    }
}
