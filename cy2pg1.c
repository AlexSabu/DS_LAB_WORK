//linked list

#include<stdio.h>
#include<stdlib.h>

struct List{
    int data;
    struct List *link;
};

void display(struct List *header){
    struct List *current=header;
    if(header==NULL){
        printf("empty\n");
        return;
    }
    for(current=header;current!=NULL;current=current->link){
        printf("%d\t",current->data);
    }
    printf("\n");
}

//inserting at beginning
struct List* insertBeg(struct List* header,int data){
    struct List* new=(struct List*)malloc(sizeof(struct List));
    new->data=data;
    new->link=NULL;
    if(header==NULL){
        header=new;
        header->link=NULL;
    }
    else{
        new->link=header;
        header=new;
    }
    return header;
}

//inserting at the end
struct List* insertEnd(struct List *header,int data){
    struct List *new=(struct List*)malloc(sizeof(struct List));
    new->data=data;
    new->link=NULL;
    struct List* current=header;
    if(header==NULL){
        header=new;
    }
    else{
        while(current->link!=NULL){
            current=current->link;
        }
        current->link=new;
    }
    return header;
}

//inserting at a particular position
struct List* insertLoc(struct List* header, int data){
    int pos,n=0;
    printf("input position:");scanf("%d",&pos);
    struct List* new=(struct List*)malloc(sizeof(struct List));
    new->data=data;
    new->link=NULL;
    struct List *current=header;
    if(pos<1){
        new->link=header;
        header=new;
        return header;
    }
    while(n<pos && current->link!=NULL){
        current=current->link;
        n++;
    }
    if(current->link==NULL){
        current->link=new;
    }
    else{
        new->link=current->link;
        current->link=new;
    }
    return header;
}
//deleting node from beginning
struct List* deleteBeg(struct List* header){
    struct List* node;
    if(header==NULL){
        printf("empty\n");
        return NULL;
    }
    else{
        node=header;
        header=header->link;
        free(node);
    }
    return header;
}
//deleting element at the end
struct List* deleteEnd(struct List* header){
    struct List* current=header, *temp;
    if(header==NULL){
        printf("empty");
        return NULL;
    }
    while(current->link!=NULL){
        temp=current;
        current=current->link;
    }
    temp->link=NULL;
    free(current);
    return header;
}

struct List* deleteLoc(struct List* header){
    int pos,n=0;
    printf("enter pos:");scanf("%d",&pos);
    struct List *current=header,*temp;
    if(header==NULL){
        printf("empty");
        return NULL;
    }
    if(pos==0){
        header=header->link;
        free(current);
        return header;
    }
    while(n<pos && current->link!=NULL){
        temp=current;
        current=current->link;
        n++;
    }
    if(current->link==NULL){
        temp->link=NULL;
        free(current);
    }
    else{
        temp->link=current->link;
        current->link=NULL;
        free(current);
    }
    return header;
}

void main(){
    int ch1,ch2,data;
    struct List* header=(struct List*)malloc(sizeof(struct List));
    header=NULL;
    while(1){
        printf("1.insert 2.delete 3.dispaly...");scanf("%d",&ch1);
    if(ch1==1){
        printf("1.beginning 2.end 3.location");scanf("%d",&ch2);
        printf("enter data: ");scanf("%d",&data);
        if(ch2==1){
            header=insertBeg(header,data);
            display(header);
        } 
        else if(ch2==2){
             header=insertEnd(header,data);
             display(header);
        }
        else if(ch2==3){
            header=insertLoc(header,data);
            display(header);
        } 
        else exit(0);
    }
    else if(ch1==2){
        printf("1.beginning 2.end 3.location");scanf("%d",&ch2);
        if(ch2==1){
            header=deleteBeg(header);
            display(header);
        }
        else if(ch2==2){
            header=deleteEnd(header);
            display(header);
        } 
        else if(ch2==3){
            header=deleteLoc(header);
            display(header);
        }
        else exit(0);
    }
    else if(ch1==3) display(header);
    else{
        printf("invalid entry");
        exit(0);
    }
    }
    free(header);
}
