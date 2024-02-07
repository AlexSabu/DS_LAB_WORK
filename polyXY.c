#include<stdio.h>
#include<stdlib.h>

struct Poly{
    int coef;
    int X;
    int Y;
};
struct Poly poly1[10],poly2[10],sum[15];
int size;

void sumPoly(struct Poly poly1[],int n1,struct Poly poly2[],int n2,struct Poly result[]){
    int i=0,j=0,k=0;
    while(i<n1 && j<n2){
        if(poly1[i].X > poly2[j].X){
            result[k]=poly1[i];
            i++;k++;
        }
        else if(poly1[i].X < poly2[j].X){
            result[k]=poly2[j];
            j++;k++;            
        }
        else{
            if(poly1[i].Y > poly2[j].Y){
                result[k]=poly1[i];
                i++;k++;            
            }
            else if(poly1[i].Y < poly2[j].Y){
                result[k]=poly2[j];
                j++;k++;                
            }
            else{
                result[k].coef=poly1[i].coef+poly2[j].coef;
                result[k].X=poly1[i].X;
                result[k].Y=poly1[i].Y;
                i++;j++;k++;
            }
        }
    }
    while(i<n1){
        result[k]=poly1[i];
        i++;k++;
    }
    while(j<n2){
        result[k]=poly2[j];
        j++;k++;
    }    
    size=k;
    for(int m=0;m<size;m++){
        sum[m].coef=result[m].coef;
        sum[m].X=result[m].X;
        sum[m].Y=result[m].Y;
    }
}

void displaySum(struct Poly result[]){
    for(int i=0;i<size;i++){
        printf(" %d(x^%d)(y^%d) ",result[i].coef,result[i].X,result[i].Y);
        if(i<size-1){
            printf("+");
        }
    }
}

void main(){
    int n1,n2;
    printf("input n1: ");scanf("%d",&n1);
    printf("poly1: ");
    for(int i=0;i<n1;i++){
        printf("term %d: ",i+1);
        scanf("%d(x^%d)(y^%d)",&poly1[i].coef,&poly1[i].X,&poly1[i].Y);
    }
    printf("input n2: ");scanf("%d",&n2);
    printf("poly2: ");
    for(int i=0;i<n2;i++){
        printf("term %d: ",i+1);
        scanf("%d(x^%d)(y^%d)",&poly2[i].coef,&poly2[i].X,&poly2[i].Y);
    }   
    sumPoly(poly1,n1,poly2,n2,sum);
    displaySum(sum);
}