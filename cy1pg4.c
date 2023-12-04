//sparse matrix
#include<stdio.h>
#include<stdlib.h>

#define MAX_ROW 10
#define MAX_COL 10
int mat1[MAX_ROW][MAX_COL],mat2[MAX_ROW][MAX_COL],tup1[MAX_ROW][3]={0},tup2[MAX_ROW][3]={0},sumtup[MAX_ROW][3]={0},tran[MAX_ROW][3]={0};
int r1,c1,r2,c2;
int count1=1,count2=1,count3;

void tuple(int mat[MAX_ROW][MAX_COL],int tup[MAX_ROW][3],int r,int c,int* count){
    tup[0][0]=r;
    tup[0][1]=c;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(mat[i][j]!=0){
                tup[*count][0]=i;
                tup[*count][1]=j;
                tup[*count][2]=mat[i][j];
                (*count)++;
            }
        }
    }
    tup[0][2]=*count-1;
}

void transpose(int tup[MAX_ROW][3],int tran[MAX_ROW][3]){
    int count=1;
    tran[0][0]=tup[0][1];
    tran[0][1]=tup[0][0];
    tran[0][2]=tup[0][2];
    for(int i=0;i<tup[0][1];i++){
        for(int j=1;j<=tup[0][2];j++){
            if(tup[j][1]==i){
                tran[count][0]=tup[j][1];
                tran[count][1]=tup[j][0];
                tran[count][2]=tup[j][2];
                count++;
            }
        }
    }
    count3=count;
}

void display(int tup[MAX_ROW][3],int r){
    for(int i=0;i<r;i++){
        printf("%d\t%d\t%d",tup[i][0],tup[i][1],tup[i][2]);
        printf("\n");
    }
}

void sum(int tup1[MAX_ROW][3],int tup2[MAX_ROW][3],int sumtup[MAX_ROW][3]){
    int i=1,j=1,k=1;
    if(tup1[0][0]!=tup2[0][0]  || tup1[0][1]!=tup2[0][1]){
        printf("cannot take sum"); exit(0);
    }
    sumtup[0][0]=tup1[0][0];
    sumtup[0][1]=tup1[0][1];
    while(i<=tup1[0][2] && j<=tup2[0][2]){
        if(tup1[i][0]<tup2[j][0]){
            sumtup[k][0]=tup1[i][0];
            sumtup[k][1]=tup1[i][1];
            sumtup[k][2]=tup1[i][2];
            i++;k++;
        }
        else if(tup1[i][0]>tup2[j][0]){
            sumtup[k][0]=tup2[j][0];
            sumtup[k][1]=tup2[j][1];
            sumtup[k][2]=tup2[j][2];
            j++;k++;
        }
        else{
            if(tup1[i][1]<tup2[j][1]){
                sumtup[k][0]=tup1[i][0];
                sumtup[k][1]=tup1[i][1];
                sumtup[k][2]=tup1[i][2];
                i++;k++;
            }
            else if(tup1[i][1]>tup2[j][1]){
                sumtup[k][0]=tup2[j][0];
                sumtup[k][1]=tup2[j][1];
                sumtup[k][2]=tup2[j][2];
                j++;k++;
            }
            else{
                sumtup[k][0]=tup1[i][0];
                sumtup[k][1]=tup1[i][1];
                sumtup[k][2]=tup1[i][2]+tup2[j][2];
                i++;j++;k++;
            }
        }
    }
    for(;i<=tup1[0][2];){
        sumtup[k][0]=tup1[i][0];
        sumtup[k][1]=tup1[i][1];
        sumtup[k][2]=tup1[i][2];
        i++;k++;
    }
    for(;j<=tup2[0][2];){
        sumtup[k][0]=tup2[j][0];
        sumtup[k][1]=tup2[j][1];
        sumtup[k][2]=tup2[j][2];
        j++;k++;
    }
    sumtup[0][2]=k-1;
}

void main(){
    printf("Enter rows and cols of mat-1:");scanf("%d %d",&r1,&c1);
    printf("Mat-1:\n");
    for(int i=0;i<r1;i++){
        for(int j=0;j<c1;j++){
            scanf("%d",&mat1[i][j]);
        }
    }
    printf("Enter rows and cols of mat-2:");scanf("%d %d",&r2,&c2);
    printf("Mat-2:\n");
    for(int i=0;i<r2;i++){
        for(int j=0;j<c2;j++){
            scanf("%d",&mat2[i][j]);
        }
    }
    tuple(mat1,tup1,r1,c1,&count1);
    printf("tuple-1:\n");
    display(tup1,count1);
    tuple(mat2,tup2,r2,c2,&count2);
    printf("tuple-2\n");
    display(tup2,count2);
    printf("sum tuple:\n");
    sum(tup1,tup2,sumtup);
    display(sumtup,sumtup[0][2]+1);
    
    printf("transpose of tuple-1:\n");
    transpose(tup1,tran);
    display(tran,count3);
    printf("transpose of tuple-2:\n");
    transpose(tup2,tran);
    display(tran,count3);
    
}