//selection sort

#include<stdio.h>
#include<stdlib.h>
int selectMin(int*, int, int);
int* swap(int*, int, int);

int* selectionSort(int arr[],int n){
    int i=0,j;
    for(i;i<n;i++){
        j=selectMin(arr,i,n);
        if(i!=j){
            arr=swap(arr,i,j);
        }
    }
    return arr;
}

int selectMin(int arr[],int i,int n){
    int j=i+1;
    int min=i;
    for(j;j<n;j++){
        if(arr[j]<arr[min]){
            min=j;
        }
    }
    return min;
}

int* swap(int arr[],int i, int j){
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
    return arr;
}

void main(){
    int n=10;
    int arr[10]={3,2,5,8,4,9,0,6,7,1};
    int* arr2;
    arr2=selectionSort(arr,n);
    for(int i=0;i<n;i++){
        printf("%d ",arr2[i]);
    }
}