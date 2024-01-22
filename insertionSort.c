//insertion sort

#include<stdio.h>
#include<stdlib.h>

int* insertionSort(int input[],int n){
    int* output=(int *)malloc(n*sizeof(int));
    output[0]=input[0];
    int i=1,key,j;
    for(i;i<n;i++){
        key=input[i];
        j=i-1;
        while(j>=0 && output[j]>key){
            output[j+1]=output[j];
            j--;
        }
        output[j+1]=key;
    }
    return output;
}

void main(){
    int* b;
    int a[9]={3,2,5,7,4,8,1,9,0};
    b=insertionSort(a,9);
    for(int i=0;i<9;i++){
        printf("%d ",b[i]);
    }
}