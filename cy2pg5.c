//binary tree using 
#include<stdio.h>
#include<stdlib.h>

struct binaryTree{
    int data;
    struct binaryTree *left;
    struct binaryTree *right;    
};
struct binaryTree *root=NULL;

//creating new nodes
struct binaryTree* createNode(int data){
    struct binaryTree *new=(struct binaryTree*)malloc(sizeof(struct binaryTree));
    new->data=data;
    new->left=new->right=NULL;
    return new;
}
//preorder traversal
void preOrder(struct binaryTree *root){
    if(root){
        printf("%d ",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}
//inorder traversal
void inOrder(struct binaryTree *root){
    if(root){
        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);
    }
}
//postorder traversal
void postOrder(struct binaryTree *root){
    if(root){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ",root->data);
    }
}
struct binaryTree* searchNode(struct binaryTree *node,int key){
    if(node==NULL || node->data==key){
        return node;
    }
    struct binaryTree *left=searchNode(node->left,key);
    if(left!=NULL){
        return left;
    }
    return searchNode(node->right,key);
}

void insertNode(int key,int data){
    struct binaryTree *node=root;
    node=searchNode(node,key);
    if(node==NULL){
        printf("no node found");exit(0);
    }
    if(node->left==NULL || node->right==NULL){
        struct binaryTree *new=createNode(data);
        int ch;
        printf("1.left 2.right: ");scanf("%d",&ch);
        if(ch==1){
            if(node->left==NULL){
                node->left=new;
            }
            else{
                printf("left already occupied");exit(0);
            }
        }
        if(ch==2){
            if(node->right==NULL){
                node->right=new;
            }else{
                printf("right already occupied");exit(0);
            }
        }
    }
    else{
        printf("sub tree of node is already occupied");
        exit(0);
    }
}

struct binaryTree* searchParent(struct binaryTree *node,int key,struct binaryTree *prev){
    //struct binaryTree *parent=NULL;
    if(node==NULL) return NULL;
    if (node->data == key) {
        return prev;
    }
    struct binaryTree *leftResult = searchParent(node->left, key, node);
    if (leftResult != NULL) {
        return leftResult;
    }
    return searchParent(node->right, key, node);
}
void deleteNode(int key) {
    if (root == NULL) {
        printf("Tree empty\n");
        return;
    }

    struct binaryTree *parent = NULL;
    parent = searchParent(root, key, NULL);

    if (parent != NULL) {
        if (parent->left != NULL && parent->left->data == key) {
            free(parent->left);
            parent->left = NULL;
        } else if (parent->right != NULL && parent->right->data == key) {
            free(parent->right);
            parent->right = NULL;
        } else {
            printf("Node is not a leaf node. No deletion\n");
        }
    } else {
        printf("Node absent. No deletion\n");
    }
}
void main(){
    int data,ch,key,val,del;
    printf("enter root data: ");scanf("%d",&data);
    root=createNode(data);
    while(1){
        printf("\n1.insert 2.pre 3.in 4.post 5.delete: ");scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("enter root node and data of new node: ");
                scanf("%d %d",&key,&val);
                insertNode(key,val);break;
            case 2:printf("\npreOrder traversal: ");
                preOrder(root);
                break;
            case 3:printf("\ninOrder traversal: ");
                inOrder(root);
                break;
            case 4:printf("\npostOrder traversal: ");
                postOrder(root);
                break;
            case 5:printf("elt to be deleted: ");scanf("%d",&del);
                deleteNode(del);
                break;
        }
    }
}