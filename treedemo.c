#include<stdio.h>
#include<stdlib.h>

struct BT {
    int data;
    struct BT *left;
    struct BT *right;
};
struct BT *root;

struct BT* createNode(int data){
    struct BT *new=(struct BT*)malloc(sizeof(struct BT));
    new->data=data;
    new->left=new->right=NULL;
    return new;
}

struct BT* searchParent(struct BT *root, int key){
    if(root==NULL || root->data==key){
        return root;
    }
    struct BT *left=searchParent(root->left,key);
    if(left) return left;
    return searchParent(root->right,key);
}

void insertNode(struct BT *root,int key){
    struct BT *parent=NULL;
    parent=searchParent(root,key);
    if(parent!=NULL){
        int ch,data;
        if(parent->left==NULL || parent->right==NULL){
            printf("enter data: ");scanf("%d",&data);
            struct BT *newNode=createNode(data);
            printf("left(1)/right(2): ");scanf("%d",&ch);
            switch(ch){
                case 1: if(parent->left==NULL){
                    parent->left=newNode;
                }else{
                    printf("left already occupied");
                }
                break;
                case 2: if(parent->right==NULL){
                    parent->right=newNode;
                }else{
                    printf("right already occupied");
                }
                break;
                default: printf("invalid entry");
                return;
            }
        }
        else{
            printf("left and right are occupied");
            return;
        }
    }
    else{
        printf("key invalid");
        return;
    }
}



int main(){
    int ch,key,rootdata;
    printf("enter root data:");scanf("%d",&rootdata);
    root=createNode(rootdata);
    while(1){
        printf("\n1.insert 2.delete 3.display 8.exit: ");scanf("%d",&ch);
        if(ch==1){
            printf("input key: ");scanf("%d",&key);
            insertNode(root,key);
        }
        else if(ch==3){
            printf("current BT: ");
            display(root);
        }
        else if(ch==8){
            printf("exiting...");
            return 0;
        }
        else{
            printf("invalid entry");
        }
    }
}