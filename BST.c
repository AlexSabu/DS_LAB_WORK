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

struct BST* min(struct BST *root){//minimum node
    if(root==NULL){
        printf("tree is empty\n");
    }
    while(root->left!=NULL){
        root=root->left;
    }
    //printf("min: %d\n",root->data);
    return root;
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

struct BST* inoder_succ(struct BST *root){
    struct BST *current=root->right,*temp=NULL;
    if(current==NULL){
        return NULL;
    }
    temp=min(current);
    return temp;
}

void deleteNode(int data){
    if(root==NULL){
        printf("root is null\n");
        return;
    }
    int c;
    struct BST *current=root,*temp=NULL;
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
            break;
        }
    }
    if(current==NULL){
        printf("no such node\n");
        return;
    }
    if(current->left==NULL && current->right==NULL){
        c=1;
    }
    else if(current->left!=NULL && current->right!=NULL){
        c=3;
    }
    else{
        c=2;
    }
    if(c==1){//current node is leaf node
        if(temp->left==current) temp->left=NULL;
        else temp->right=NULL;
        free(current);
    }
    else if(c==2){//current has one child
        if(temp->left==current){
            if(current->left!=NULL){
                temp->left=current->left;
                current->left=NULL;
            }
            else{
                temp->left=current->right;
                current->right=NULL;
            }
        }
        else{
            if(current->left!=NULL){
                temp->right=current->left;
                current->left=NULL;
            }
            else{
                temp->right=current->right;
                current->right=NULL;
            }
        }
        free(current);
    }
    else{//current has two child
        struct BST *succ=inoder_succ(current);
        if(succ==NULL){
            return;
        }
        int s=succ->data;
        deleteNode(s);
        current->data=s;
    }
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
    struct BST *what=min(root);
    printf("min: %d",what->data);
    max(root);

    //deleteNode(6);
    deleteNode(4);
    inorder(root); printf("\n");   
    return 0;
}
