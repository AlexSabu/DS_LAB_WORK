#include<stdio.h>
#include<stdlib.h>

struct MemoryBlock{
    int size;
    struct MemoryBlock *prev, *next;
};
struct MemoryBlock *header=NULL;

struct MemoryBlock* createBlock(int size){
    struct MemoryBlock *block=(struct MemoryBlock*)malloc(sizeof(struct MemoryBlock));
    if(!block){
        printf("memory allocation failed");
        return NULL;
    }
    block->next=block->prev=NULL;
    block->size=size;
    return block;
}

void allocate(int size){
    struct MemoryBlock *block=createBlock(size);
    if(header==NULL){
        header=block;
        return;
    }
    struct MemoryBlock *current=header;
    while (current->next!=NULL){
        current=current->next;
    }
    current->next=block;
    block->prev=current;
}

void garbageCollector(int size){
    if(header==NULL){
        printf("memory pool is empty");
        exit(0);
    }
    struct MemoryBlock *current=header,*prev=NULL;
    while(current->next!=NULL && current->size!=size){
        prev=current;
        current=current->next;
    }
    if(current->next==NULL && current->size!=size){
        printf("size unavailable\n");
        return;
    }
    else if(current->next==NULL && current->size==size){
        current->prev=NULL;
        if(prev!=NULL){
            prev->next=NULL;
        }
        else{
            header=NULL;
        }
        free(current);
    }
    else{
        if(prev==NULL){
            header=header->next;
            header->prev=NULL;
            current->next=NULL;
            free(current);
        }
        else{
            prev->next=current->next;
            current->next->prev=prev;
            current->next=current->prev=NULL;
            free(current);
        }
    }
}

void memeoryStatus(){
    printf("memory pool: \n");
    if(header==NULL){
        printf("empty\n");
        return;
    }
    int i=1;
    struct MemoryBlock *current=header;
    while(current!=NULL){
        printf("memory block-%d, size: %d\n",i,current->size);
        i++;
        current=current->next;
    }
}

void main(){
    int size,ch;
    while(1){
        printf("1.allocate 2.free 3.display: ");scanf("%d",&ch);
        switch(ch){
            case 1: printf("size: ");scanf("%d",&size);
                allocate(size);
                memeoryStatus();
                break;
            case 2: printf("size: ");scanf("%d",&size);
                garbageCollector(size);
                memeoryStatus();
                break;
            case 3: memeoryStatus();break;
            default: printf("invalid choice\n");exit(0);
        }
    }
}
