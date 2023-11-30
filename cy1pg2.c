//infix-postfix
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int precedence(char);

char infix[100],postfix[100],stack1[100];
int top=-1;
float stack2[100]={0};

void push1(char ch,int *top){
    (*top)++;
    stack1[*top]=ch;

}
char pop1(int *top){
    return stack1[(*top)--];
}

void inToPost(char infix[]){
    int j=0;
    char symbol,temp;
    int len=strlen(infix);
    for(int i=0;i<len;i++){
        symbol=infix[i];
        switch(symbol){
            case '(': push1(symbol,&top);break;
            case ')': while((temp=pop1(&top))!='('){
                        postfix[j]=temp;
                        j++;
                    }
                    break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
            while(precedence(stack1[top])>=precedence(symbol)){
                postfix[j]=pop1(&top);
                j++;
            }
            push1(symbol,&top);
            break;
            default: postfix[j]=symbol;j++;
        }
    }
    while(top!=-1){
        postfix[j]=pop1(&top);
        j++;
    }
    postfix[j]='\0';
    top=-1;
}

int precedence(char symbol){
    switch(symbol){
        case '^':return 3;
        case '*':
        case '/':return 2;
        case '+':
        case '-':return 1;
        default: return 0;
    }
}
void push2(float val){
    top++;
    stack2[top]=val;
}
float pop2(){
    return stack2[top--];
}

int postEval(){
    char symbol;
    int len=strlen(postfix);
    for(int i=0;i<len;i++){
        symbol=postfix[i];
        if(symbol>=48 && symbol<=57){
            push2((int)symbol-48);
        }
        else{
            float a=pop2(),b=pop2();
            switch(symbol){
                case '+':push2(b+a);break;
                case '-':push2(b-a);break;
                case '*':push2(b*a);break;
                case '/':push2(b/a);break;
                case '^':push2(pow(b,a));break;
                default: continue;
            }
        }
    }
    return pop2();
}

void main(){
    printf("enter infix expression: ");scanf("%s",infix);
    inToPost(infix);
    printf("postfix : %s",postfix);
    float result=0.0;
    result=postEval();
    printf("\nvalue: %f",result);

}