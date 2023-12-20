//polynomial
#include<stdio.h>
#include<stdlib.h>

int compare(int,int);
void attach(int,int);

struct Poly{
    int coef;
    int expon;
};
struct Poly poly1[100],poly2[100],poly3[100];
int n1,n2,n3=0;

void display(struct Poly poly[],int n){
    int i=0;
    if(n==0){
        printf("no polynomial\n");
        return;
    }
    while(i<n){
        printf("%dx^%d",poly[i].coef,poly[i].expon);
        if(i!=n-1){
            printf("+");
        }
        i++;
    }
    printf("\n");
}

void sum(){
    int count1=0,count2=0;
    if(n1==0 || n2==0){
        if(n1==0){
            display(poly2,n2);
            return;
        }
        else{
            display(poly1,n1);
            return;
        }
    }
    while(count1<n1 && count2<n2){
        int c=compare(poly1[count1].expon,poly2[count2].expon);
        switch(c){
            case -1:
                attach(poly2[count2].coef,poly2[count2].expon);
                count2++;n3++;
                break;
            case 0:
                attach(poly2[count2].coef+poly1[count1].coef,poly2[count2].expon);
                count1++;
                count2++;n3++;
                break;
            case 1:
                attach(poly1[count1].coef,poly1[count1].expon);
                count1++;n3++;
                break;
        }
    }
    for(;count1<n1;count1++){
        attach(poly1[count1].coef,poly1[count1].expon);
        n3++;
    }
    for(;count2<n2;count2++){
        attach(poly2[count2].coef,poly2[count2].expon);
        n3++;
    }

}

int compare(int e1,int e2){
    if(e1>e2) return 1;
    else if(e1<e2) return -1;
    else return 0;
}

void attach(int coef,int exp){
    poly3[n3].coef=coef;
    poly3[n3].expon=exp;
}

void main(){
    printf("n1: ");scanf("%d",&n1);
    printf("poly-1: \n");
    for(int i=0;i<n1;i++){
        printf("term %d: ",i+1);
        scanf("%dx^%d",&poly1[i].coef,&poly1[i].expon);
    }
    printf("n2: ");scanf("%d",&n2);
    printf("poly-2: \n");
    for(int i=0;i<n2;i++){
        printf("term %d: ",i+1);
        scanf("%dx^%d",&poly2[i].coef,&poly2[i].expon);
    }
    printf("poly1: ");display(poly1,n1);
    printf("poly2 :");display(poly2,n2);
    sum();
    printf("sum: ");display(poly3,n3);
}
