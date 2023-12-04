//circular queue
#include<stdio.h>
#include<stdlib.h>

int cirq[100]={0};
int front=-1,rear=-1,n;

void enqueue(int data){
    if(front==(rear+1)%n){
        printf("cir : full");exit(0);
    }
    if(rear==n-1) rear=0;
    else if(rear==-1) rear=front=0;
    else rear++;
    cirq[rear]=data;
}
void dequeue(){
    if(front==-1){printf("cir : empty");exit(0);}
    printf("deleted elt: %d\n",cirq[front]);
    if(front==n-1) front=0;
    else if(front==rear) front=rear=-1;
    else front++;
}
void display(){
    printf("cir: ");
    if(front==-1){printf("empty");return;}
    int i=front;
    while(i!=rear){
        printf("%d  ",cirq[i]);
        i=(i+1)%n;
    }
    printf("%d\n",cirq[rear]);
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