//binary search tree
#include<stdio.h>
#include<stdlib.h>

//structure for binary tree
struct BST{
    int data;
    struct BST *left;
    struct BST *right;
};
struct BST *root=NULL;

//struct BST* findMin(struct BST*);

struct BST* createNode(int data){
    struct BST *new=(struct BST*)malloc(sizeof(struct BST));
    new->data=data;
    new->left=new->right=NULL;
    return new;
}
//inserting node
struct BST* insertNode(struct BST *node, int data){
    if(node==NULL){
        return createNode(data);
    }
    if(data<node->data){
        node->left=insertNode(node->left,data);
    }
    else if(data>node->data){
        node->right=insertNode(node->right,data);
    }
    else{
        printf("node already exits");
        exit(0);
    }
    return node;
}
struct BST* delete(struct BST *node,int key){
    if(node==NULL){
        return node;
    }
    if(key<node->data){
        node->left=delete(node->left,key);
    }
    else if(key>node->data){
        node->right=delete(node->right,key);
    }
    else{
        if(node->left==NULL && node->right==NULL){
            free(node);
            return NULL;
        }
        //node with one child
        if(node->left==NULL){
            struct BST *temp=node->right;
            free(node);
            return temp;
        }
        else if(node->right==NULL){
            struct BST *temp=node->left;
            free(node);
            return temp;
        }
        else{
            printf("non-leaf node cannot be deleted");
            exit(0);
        }
            /*
        else{//node with two children
            struct BST *temp=findMin(node->right);
            node->data=temp->data;
            node->right=delete(node->right,key);
        }*/
    }
    return node;
}/*
struct BST* findMin(struct BST *node){
    while(node->left!=NULL){
        node=node->left;
    }
    return node;
}*/

//search funtion
struct BST* search(struct BST *node,int key){
    if(node==NULL || node->data==key){
        return node;
    }
    if(key<node->data){
        return search(node->left,key);
    }
    else{
        return search(node->right,key);
    }
}

//inorder traversal
void inOrder(struct BST *node){
    if(node){
        inOrder(node->left);
        printf("%d ",node->data);
        inOrder(node->right);
    }
}
void main(){
    int data,ch;
    printf("enter root: ");scanf("%d",&data);
    root=createNode(data);
    while(1){
        int val,del,sr;
        printf("1.insert 2.delete 3.search 4.display 5.exit: ");scanf("%d",&ch);
        switch(ch){
            case 1:printf("enter data: ");scanf("%d",&val);
                root=insertNode(root,val);
                printf("binary search tree: ");
                inOrder(root);
                printf("\n");break;;
                break;
            case 2:printf("data to be deleted: ");scanf("%d",&del);
                root=delete(root,del);
                printf("binary search tree: ");
                inOrder(root);
                printf("\n");break;
            case 3:printf("search key: ");scanf("%d",&sr);
            struct BST *check=search(root,sr);
            if(check==NULL) printf("element absent\n");
            else printf("element present\n");
            case 4:printf("inorder traversal: ");
                inOrder(root);
                printf("\n");
                break;
            default: exit(0);
        }
    }
}

