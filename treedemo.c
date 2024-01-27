#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct BT {
    int data;
    struct BT *left;
    struct BT *right;
};
struct BT *root;

struct Queue{
    struct BT *node;
};
struct Queue queue[50];
int front=-1,rear=-1;

void Enqueue(struct Queue *queue,struct BT *node){
    if(front==(rear+1)%50){
        printf("queue is full");
        exit(0);
    }
    if(rear==49) rear=0;
    else if(front==-1) front=rear=0;
    else rear++;
    queue[rear].node=node;
}
struct BT* Dequeue(struct Queue *queue){
    if(front==-1){
        printf("queue is empty");
        exit(0);
    }
    struct BT *node=queue[front].node;
    if(front==49) front=0;
    else if(front==rear) front=rear=-1;
    else front++;
    return node;
}
bool isEmpty(struct Queue *queue){
    if(front==-1) return true;
    return false;
}
void clearQueue(struct Queue *queue){
    int i=front;
    while(i!=rear){
        queue[i++].node=NULL;
        i=(i+1)%50;
    }
    queue[rear].node=NULL;
    front=rear=-1;
}

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
    return;
}

struct BT* searchParent2(struct BT *root,int key,struct BT *parent){
    if(root==NULL) return root;
    if(root->data==key) return parent;
    struct BT *left=searchParent2(root->left,key,root);
    if(left) return left;
    return searchParent2(root->right,key,root);
}

void deleteNode(struct BT *root, int key){
    struct BT *parent=NULL;
    parent=searchParent2(root,key,parent);
    if(parent){
        struct BT *left=parent->left,*right=parent->right;
        if(left){
            if(left->data==key){
                if(left->left==NULL && left->right==NULL){
                    parent->left=NULL;
                    free(left);
                    return;
                }else{
                    printf("not a leaf node. cannot delete");
                    return;
                }
            }
        }
        if(right){
            if(right->data==key){
                if(right->left==NULL && right->right==NULL){
                    parent->right=NULL;
                    free(right);
                    return;
                }
                else{
                    printf("not a leaf node. cannot delete");
                    return;                                        
                }
            }
        }
    }else{
        if(root->data==key){
            printf("cannot delete root");
            return;
        }
        printf("node does not exist");
        return;
    }
}



void levelOrder(struct BT *root,struct Queue *queue){//level order using queue
    struct BT *temp=NULL;
    if(!root){
        printf("root is null");
        return;
    }
    Enqueue(queue,root);
    while(!isEmpty(queue)){
        temp=Dequeue(queue);
        printf("%d  ",temp->data);
        if(temp->left) Enqueue(queue,temp->left);
        if(temp->right) Enqueue(queue,temp->right);
    }
    clearQueue(queue);
}

void Maximum_Minimum(struct BT *root,struct Queue *queue){//maximum elt+minimum etl
    struct BT *temp=NULL;
    int max,min;
    if(!root){
        printf("root is null");
        return;
    }
    Enqueue(queue,root);
    max=root->data;
    min=root->data;
    while(!isEmpty(queue)){
        temp=Dequeue(queue);
        if(max<=temp->data) 
            max=temp->data;
        if(min>=temp->data) 
            min=temp->data;
        if(temp->left) Enqueue(queue,temp->left);
        if(temp->right) Enqueue(queue,temp->right);
    }
    clearQueue(queue);
    printf("max: %d, min: %d",max,min);
}

int main(){
    int ch,key,rootdata;
    printf("enter root data:");scanf("%d",&rootdata);
    root=createNode(rootdata);
    while(1){
        printf("\n1.insert 2.delete 3.display 4.level_order 5.max+min 8.exit: ");scanf("%d",&ch);
        if(ch==1){
            printf("input key: ");scanf("%d",&key);
            insertNode(root,key);
        }
        else if(ch==2){
            printf("input key: ");scanf("%d",&key);
            deleteNode(root,key);
        }        
        else if(ch==3){
            printf("current BT: ");
            display(root);
        }
        else if(ch==4){
            printf("current BT (using level-order): ");
            levelOrder(root,queue);
        }
        else if(ch==5){
            Maximum_Minimum(root,queue);
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