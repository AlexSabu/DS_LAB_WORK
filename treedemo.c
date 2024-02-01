#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct BT {//Bt node
    int data;
    struct BT *left;
    struct BT *right;
};
struct BT *root;
struct BT *temp_root;//for identical function

struct Queue{//queue
    struct BT *node;
};
struct Queue queue[500];
int front=-1,rear=-1;

void Enqueue(struct Queue *queue,struct BT *node){//inserting node to cir-queue
    if(front==(rear+1)%500){
        printf("queue is full");
        exit(0);
    }
    if(rear==499) rear=0;
    else if(front==-1) front=rear=0;
    else rear++;
    queue[rear].node=node;
}
struct BT* Dequeue(struct Queue *queue){//deleting node from cir-queue
    if(front==-1){
        printf("queue is empty");
        exit(0);
    }
    struct BT *node=queue[front].node;
    if(front==499) front=0;
    else if(front==rear) front=rear=-1;
    else front++;
    return node;
}
bool isEmpty(struct Queue *queue){//checking if cir-queue is empty
    if(front==-1) return true;
    return false;
}
void clearQueue(struct Queue *queue){//clearing queue
    int i=front;
    while(i!=rear){
        queue[i].node=NULL;
        i=(i+1)%500;
    }
    queue[rear].node=NULL;
    front=rear=-1;
}

struct BT* createNode(int data){//creating node
    struct BT *new=(struct BT*)malloc(sizeof(struct BT));
    new->data=data;
    new->left=new->right=NULL;
    return new;
}

struct BT* searchParent(struct BT *root, int key){//dearch parent for insertion
    if(root==NULL || root->data==key){
        return root;
    }
    struct BT *left=searchParent(root->left,key);
    if(left) return left;
    return searchParent(root->right,key);
}

void insertNode(struct BT *root,int key){//inserting node
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

struct BT* searchParent2(struct BT *root,int key,struct BT *parent){//search parent for deletion
    if(root==NULL) return root;
    if(root->data==key) return parent;
    struct BT *left=searchParent2(root->left,key,root);
    if(left) return left;
    return searchParent2(root->right,key,root);
}

void deleteNode(struct BT *root, int key){//dealeting node
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

void display(struct BT *root){//inorder traversal

    if(root){
        display(root->left);
        printf("%d\t",root->data);
        display(root->right);
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

    int sizeWithRec(struct BT *root){//size of b-tree
        if(root==NULL){
            return 0;
        }
        else{
            return(sizeWithRec(root->left)+1+(sizeWithRec(root->right)));
        }
    }

    int sizeWithoutRec(struct BT *root,struct Queue *queue){//size of b-tree
        struct BT *temp=NULL;
        int size=0;
        if(root==NULL){
            return 0;
        }
        Enqueue(queue,root);
        while(!isEmpty(queue)){
            temp=Dequeue(queue);
            size++;
            if(temp->left){
                Enqueue(queue,temp->left);
            }
            if(temp->right){
                Enqueue(queue,temp->right);
            }
        }
        clearQueue(queue);
        return size;
    }

    //height of a tree
    int heightRec(struct BT *root){
        int left,right;
        if(root==NULL){
            return 0;
        }
        left=heightRec(root->left);
        right=heightRec(root->right);
        if(left>right){
            return (left+1);
        }
        else{
            return (right+1);
        }
    }

    int heightWithoutRec(struct BT *root, struct Queue *queue){//height of a tree
        struct BT *temp=NULL;
        if(root==NULL){
            return 0;
        }
        int level=0;
        Enqueue(queue,NULL);
        while(!isEmpty(queue)){
            temp=Dequeue(queue);
            if(temp==NULL){
                if(!isEmpty(queue)){
                    Enqueue(queue,NULL);
                }
                level++;
            }
            else{
                if(temp->left){
                    Enqueue(queue,temp->left);
                }
                if(temp->right){
                    Enqueue(queue,temp->right);
                }
            }
        }
        return level;
    }

    void deepest(struct BT *root, struct Queue *queue){//deepest node
        struct BT *temp=NULL;
        if(root==NULL){
            printf("empty tree");
            return;
        }
        Enqueue(queue,root);
        while(!isEmpty(queue)){
            temp=Dequeue(queue);
            if(temp->left){
                Enqueue(queue,temp->left);
            }
            if(temp->right){
                Enqueue(queue,temp->right);
            }
        }
        printf("deepest: %d",temp->data);
        clearQueue(queue);
    }

    int noLeafNodes(struct BT *root, struct Queue *queue){//no. of leaf nodes
        struct BT *temp;
        if(root==NULL){
            return 0;
        }
        int count=0;
        Enqueue(queue,root);
        while(!isEmpty(queue)){
            temp=Dequeue(queue);
            if(temp->left==NULL && temp->right==NULL){
                count++;
            }
            if(temp->left){
                Enqueue(queue,temp->left);
            }
            if(temp->right){
                Enqueue(queue,temp->right);
            }
        }
        return count;
    }

//checking if trees are structurally identical
int identical(struct BT *root1,struct BT *root2){
    if(root1==NULL && root2==NULL){
        return 1;
    }
    else if(root1==NULL || root2==NULL){
        return 0;
    }
    else{
        return (root1->data==root2->data && identical(root1->left,root2->left) && identical(root1->right,root2->right));
    }
}

//finding level with highest sum
int levelSum(struct BT *root,struct Queue *queue){
    struct BT *temp;
    if(root==NULL){
        return 0;
    }
    int level=0,maxLevel=0,currentSum=0,maxSum=0;
    Enqueue(queue,root);
    Enqueue(queue,NULL);
    while(!isEmpty(queue)){
        temp=Dequeue(queue);
        if(temp==NULL){
            if(currentSum>maxSum){
                maxSum=currentSum;
                maxLevel=level;
            }
            level++;
            currentSum=0;
            if(!isEmpty(queue))
                Enqueue(queue,NULL);
        }
        else{
            currentSum+=temp->data;
            if(root->left){
                Enqueue(queue,temp->left);
            }
            if(root->right){
                Enqueue(queue,temp->right);
            }
        }
    }
    clearQueue(queue);
    return maxLevel;

}



int main(){
    int ch,ch2,key,rootdata;
    printf("enter root data:");scanf("%d",&rootdata);
    root=createNode(rootdata);
    while(1){
        clearQueue(queue);
        printf("\n1.insert 2.delete 3.display 4.level_order 5.max+min 6.sizeWithRec 7.sizeWithoutRec 8.height 9.deepest_node 10.leaf_nodes 12.mirror 19.exit: ");scanf("%d",&ch);
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
        else if(ch==6){
            printf("size: %d",sizeWithRec(root));
        } 
        else if(ch==7){
            printf("size: %d",sizeWithoutRec(root,queue));
        } 
        else if(ch==8){
            printf("rec or not: ");scanf("%d",&ch2);
            if(ch2==1) printf("height: %d",heightRec(root));
            else printf("height: %d",heightWithoutRec(root,queue));
        }
        else if(ch==9){
            deepest(root,queue);
        }
        else if(ch==10){
            printf("size: %d",noLeafNodes(root,queue));
        }    
        else if(ch==11){
            printf("level: %d",levelSum(root,queue));
        }
        else if(ch==12){
            mirror(root);
            printf("mirrored :");
            display(root);
        }
        else if(ch==19){
            printf("exiting...");
            return 0;
        }
        else{
            printf("invalid entry");
        }
    }
}