//stack using linked list

#include<stdio.h>
#include<stdlib.h>

struct Stack{
    int val;
    struct Stack *link;
};
struct Stack *stk=NULL;

void push(int elt){
    struct Stack *new=(struct Stack *)malloc(sizeof(struct Stack));
    if(new==NULL){
        printf("stack overflow");
        return;
    }
    struct Stack *current=stk;
    new->val=elt;
    new->link=NULL;
    if(stk==NULL){
        new->link=stk;
        stk=new;
        current=new;
    }
    else{
        while(current->link!=NULL){
            current=current->link;
        }
        current->link=new;
    }
}
void pop(){
    struct Stack *current=stk,*temp=NULL;
    if(stk==NULL){
        printf("stack underflow");
        exit(0);
    }
    else{
        while(current->link!=NULL){
            temp=current;
            current=current->link;
        }
        if(temp==NULL){
            printf("\ndeleted elt: %d",current->val);
            free(current);
            stk=NULL;
            return;
        }
        printf("\ndeleted elt: %d",current->val);
        temp->link=NULL;
        free(current);
    }
}
void display(){
    printf("\nstack: ");
    struct Stack *current=stk;
    if(current==NULL){
        printf("stack empty");
        return;
    }
    else{
        while(current!=NULL){
            printf("%d\t",current->val);
            current=current->link;
        }
    }
}

int main(){
    int ch,elt;
    while(1){
        printf("\n1.push 2.pop 3.display 4.exit..");scanf("%d",&ch);
        if(ch==1){
            printf("elt: ");scanf("%d",&elt);
            push(elt);
            display();
        }
        else if(ch==2){
            pop();
            display();
        }
        else if(ch==3){
            display();
        }
        else return -1;
    }
}
