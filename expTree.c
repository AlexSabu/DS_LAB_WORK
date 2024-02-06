#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char infix[100],postfix[100];
char stk[50];
int top=-1;

struct BT{
    int data;
    struct BT *left;
    struct BT *right;
};
struct BT *root=NULL;

struct Stack{
    int top;
    struct BT *s[30];
};
struct Stack stack;

void push2(struct BT *node){
    stack.s[++(stack.top)]=node;
}
struct BT* pop2(){
    return stack.s[stack.top--];
}

void push(char data){
    stk[++top]=data;
}
char pop(){
    return stk[top--];
}

int precedence(char symbol){
    switch(symbol){
        case '^':return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}

void infix_To_postfix(){
    int i=0,len,j=0;
    char symbol,temp;
    len=strlen(infix);
    for(i=0;i<len;i++){
        symbol=infix[i];
        switch(symbol){
            case '(': push(symbol); break;
            case ')': 
                while((temp=pop())!='('){
                    postfix[j]=temp;
                    j++;
                }
                break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
                while(top != -1 && precedence(stk[top]) >= precedence(symbol) && stk[top] != '('){
                    postfix[j]=pop();
                    j++;
                }
                push(symbol);
                break;
            default: 
                postfix[j]=symbol;
                j++;
        }
    }
    while(top!=-1){
        postfix[j]=pop();
        j++;
    }
    postfix[j]='\0';
}

struct BT* createNode(int data){//creating node
    struct BT *new=(struct BT*)malloc(sizeof(struct BT));
    new->data=data;
    new->left=new->right=NULL;
    return new;
}

void expqwe(char postfix[]){
    int len=strlen(postfix);
    char symbol;
    for(int i=0;i<len;i++){
        symbol=postfix[i];
        if(symbol>=48 && symbol<=57){
            struct BT *new=createNode((int)symbol-'0');
            push2(new);
        }
        else{
            struct BT *op2=pop2();
            struct BT *op1=pop2();
            struct BT *new=createNode((int)symbol);
            new->left=op1;
            new->right=op2;
            push2(new);
        }
    }
}

// void inorder(struct BT *root){
//     if(root){
//         inorder(root->left);
//         printf("%c ",(char)root->data);
//         inorder(root->right);
//     }
// }
void inorder(struct BT *root){
    if(root){
        inorder(root->left);
        if(root->data >= '0' && root->data <= '9') {
            printf("%d ", root->data);
        } else {
            printf("%c ", (char)root->data);
        }
        inorder(root->right);
    }
}


int main(){
    printf("infix: ");scanf("%s",infix);
    infix_To_postfix();
    printf("postfix: %s\n",postfix);
    stack.top=-1;
    expqwe(postfix);
    root=stack.s[0];
    printf("bt: ");
    inorder(root);
}