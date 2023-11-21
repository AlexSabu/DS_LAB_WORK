//polynomial using linked list
#include<stdio.h>
#include<stdlib.h>

struct Poly{
    int expon;
    int coef;
    struct Poly *link;
};
struct Poly *poly1=NULL,*poly2=NULL,*poly3=NULL,*poly4=NULL;
int n1,n2;
//creating new terms
struct Poly* create(struct Poly *poly,int n){
    int expon;
    float coef;
    for(int i=0;i<n;i++){
        struct Poly *new=(struct Poly*)malloc(sizeof(struct Poly));
        struct Poly *current=poly;
        printf("term %d:",i+1);scanf("%dx^%d",&new->coef,&new->expon);
        new->link=NULL;
        if(poly==NULL){
            poly=new;
        }
        else{
            while(current->link!=NULL){
                current=current->link;
            }
            current->link=new;
        }
    }
    return poly;
}
//displaying the polynomial
void display(struct Poly *poly){
    struct Poly *current=poly;
    if(poly==NULL){
        printf("empty\n");
        return;
    }
    else{
        while(current!=NULL){
            printf("%dx^%d",current->coef,current->expon);
            if(current->link!=NULL){
                printf("+");
            }
            current=current->link;
        }
    }
    printf("\n");
}

int compare(int e1,int e2){
    if(e1>e2) return 1;
    else if(e1<e2) return -1;
    else return 0;
}

void attach(int coef,int expon){
    struct Poly *current=poly3;
    struct Poly *new=(struct Poly*)malloc(sizeof(struct Poly));
    new->coef=coef;new->expon=expon;new->link=NULL;
    if(poly3==NULL){
        poly3=new;
        return;
    }
    while(current->link!=NULL){
        current=current->link;
    }
    current->link=new;
    return;
}
//taking sum
void sum(){
    struct Poly *current1=poly1,*current2=poly2;
    while(current1!=NULL && current2!=NULL){
        int a=compare(current1->expon,current2->expon);
    if(a>0){
        attach(current1->coef,current1->expon);
        current1=current1->link;
    }
    else if(a<0){
        attach(current2->coef,current2->expon);
        current2=current2->link;
    }
    else{
        attach(current1->coef+current2->coef,current1->expon);
        current1=current1->link;
        current2=current2->link;
    }
    }
    while(current1!=NULL){
        attach(current1->coef,current1->expon);
        current1=current1->link;
    }
    while(current2!=NULL){
        attach(current2->coef,current2->expon);
        current2=current2->link;
    }

}
//finding product
void product(){
    struct Poly *current1=poly1;
    if(poly1==NULL || poly2==NULL){
        printf("cannot take product");
        exit(1);
    }
    while(current1!=NULL){
        struct Poly *current2=poly2;
        while(current2!=NULL){
            int coef=current1->coef*current2->coef;
            int expon=current1->expon+current2->expon;
            struct Poly *temp1=poly4,*temp2=NULL;
            if(poly4==NULL){
                struct Poly *new=(struct Poly*)malloc(sizeof(struct Poly));
                new->coef=coef;
                new->expon=expon;
                new->link=NULL;
                poly4=new;
                temp1=new;
            }
            else{
                while(temp1!=NULL && temp1->expon > expon){
                    temp2=temp1;
                    temp1=temp1->link;
                }
                if(temp1!=NULL && temp1->expon==expon){
                    temp1->coef+=coef;
                }
                else{
                    struct Poly *new=(struct Poly*)malloc(sizeof(struct Poly));
                    new->coef=coef;
                    new->expon=expon;
                    new->link=NULL;
                    if(temp2==NULL){
                        new->link=poly4;
                        poly4=new;
                    }
                    else{
                        temp2->link=new;
                        new->link=temp1;
                    }
                }
            }
            current2=current2->link;
        }
        current1=current1->link;
    }
}

int main(){
    printf("enter n1:");scanf("%d",&n1);
    poly1=create(poly1,n1);
    printf("enter n2:");scanf("%d",&n2);
    poly2=create(poly2,n2);
    printf("poly-1: ");display(poly1);
    printf("poly-2: ");display(poly2);
    sum();
    printf("sum poly: ");display(poly3);
    product();
    printf("product: ");display(poly4);
}
