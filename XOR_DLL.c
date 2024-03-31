#include<stdio.h>
#include<stdlib.h>

struct DLL{
    int data;
    struct DLL *xor_link;
};
struct DLL *head=NULL;

//Function to find new pointer
struct DLL* XOR(struct DLL *a,struct DLL *b){
    return (struct DLL*)((unsigned long)a ^ (unsigned long)b);
}

struct DLL* createNode(int data){
    struct DLL* new=(struct DLL*)malloc(sizeof(struct DLL));
    new->data=data;
    new->xor_link=NULL;
    return new;
}

struct DLL* insert(struct DLL *head,int data){
    struct DLL *new=createNode(data);
    new->xor_link=head;

    if(head!=NULL){
        head->xor_link=XOR(new,head->xor_link);
        head=new;
    }
    else{
        head=new;
    }
    return head;
}

void display(struct DLL *head){
    struct DLL *current=head;
    struct DLL *prev=NULL;
    struct DLL *next;
    if(head==NULL){
        printf("empty\n");
        return;
    }
    while(current!=NULL){
        printf("%d  ",current->data);
        next=XOR(prev,current->xor_link);
        prev=current;
        current=next;
    }
    printf("\n");
    return;
}

int main(){
    head=insert(head,1);
    head=insert(head,12);
    head=insert(head,56);
    head=insert(head,78);
    head=insert(head,4);
    display(head);

}