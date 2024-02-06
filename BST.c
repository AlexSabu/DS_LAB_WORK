#include<stdio.h>
#include<stdlib.h>

struct BST{
    int data;
    struct BST *left;
    struct BST *right;
};
struct BST *root=NULL;

struct BST* createNode(int data){
    struct BST *new=(struct BST*)malloc(sizeof(struct BST));
    new->data=data;
    new->right=NULL;
    new->left=NULL;
    return new;
}

void insertNode(int data){
    struct BST *current=root,*temp=NULL;
    if(root==NULL || root->data==data){
        if(root==NULL){
            printf("root is null");
            return;
        }
        printf("already exists\n");
        return;
    }
    while(current!=NULL){
        if(current->data > data){
            temp=current;
            current=current->left;
        }
        else if(current->data < data){
            temp=current;
            current=current->right;
        }
        else{
            printf("data already exists");
            return;
        }
    }
    if(current==NULL){
        struct BST *new=createNode(data);
        if(temp->data > data) temp->left=new;
        else temp->right=new;
    }
}

void inorder(struct BST *root){
    if(root){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

void min(struct BST *root){//minimum node
    if(root==NULL){
        printf("tree is empty\n");
    }
    while(root->left!=NULL){
        root=root->left;
    }
    printf("min: %d\n",root->data);
}

void max(struct BST *root){//maximum node
    if(root==NULL){
        printf("tree is empty\n");
    }
    while(root->right!=NULL){
        root=root->right;
    }
    printf("max: %d\n",root->data);
}

int main(){
    root=createNode(4);

    insertNode(2);
    insertNode(6);
    insertNode(1);
    insertNode(3);
    insertNode(5);
    insertNode(7);   

    printf("BST: ");   
    inorder(root); printf("\n");

    min(root);
    max(root);
    return 0;
}
