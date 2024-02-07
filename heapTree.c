#include<stdio.h>
#include<stdlib.h>

struct heapTree{
    int size;
    int *arr;
};
struct heapTree *maxHeap,*minHeap;

void heapifyMax(int[],int,int);

void heapifyMax(int arr[],int i,int n){
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<n && arr[left]>=arr[largest]){
        largest=left;
    }
    if(right<n && arr[right]>arr[largest]){
        largest=right;
    }
    if(largest!=i){
        int temp=arr[i];
        arr[i]=arr[largest];
        arr[largest]=temp;
        heapifyMax(arr,largest,n);
    }
}

void createMax(int arr[],int n){
    maxHeap=(struct heapTree*)malloc(sizeof(struct heapTree));
    maxHeap->size=n;
    maxHeap->arr=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        maxHeap->arr[i]=arr[i];
    }
    for(int i=n/2-1;i>=0;i--){
        heapifyMax(maxHeap->arr,i,n);
    }
    printf("max heap: ");
    for(int i=0;i<n;i++){
        printf("%d ",maxHeap->arr[i]);
    }
    printf("\n");
}

void heapifyMin(int arr[],int i, int n){
    int smallest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<n && arr[left]<arr[smallest]){
        smallest=left;
    }
    if(right<n && arr[right]<arr[smallest]){
        smallest=right;
    }
    if(smallest!=i){
        int temp=arr[i];
        arr[i]=arr[smallest];
        arr[smallest]=temp;
        heapifyMin(arr,smallest,n);       
    }
}

void createMin(int arr[],int n){
    minHeap=(struct heapTree*)malloc(sizeof(struct heapTree));
    minHeap->size=n; 
    minHeap->arr=(int*)malloc(n*sizeof(int));   
    for(int i=0;i<n;i++){
        minHeap->arr[i]=arr[i];
    }    
    for(int i=n/2-1;i>=0;i--){
        heapifyMin(minHeap->arr,i,n);
    }
    printf("min heap: ");
    for(int i=0;i<n;i++){
        printf("%d ",minHeap->arr[i]);
    }
    printf("\n");    
}

void insert(struct heapTree *heap,int data,int check){
    heap->size++;
    int n=heap->size;
    heap->arr=realloc(heap->arr,heap->size*sizeof(int));
    heap->arr[n-1]=data;
    if(check==1){
        for(int i=n/2-1;i>=0;i--){
            heapifyMax(maxHeap->arr,i,n);
        }
        printf("max heap: ");
        for(int i=0;i<n;i++){
            printf("%d ",maxHeap->arr[i]);
        }
        printf("\n");
    }
    else{
        for(int i=n/2-1;i>=0;i--){
            heapifyMin(minHeap->arr,i,n);
        }    
        printf("min heap: ");
        for(int i=0;i<n;i++){
            printf("%d ",minHeap->arr[i]);
        }
        printf("\n"); 
    }
}

void delete(struct heapTree *heap,int data,int check){
    int n=heap->size,flag=0,index;
    for(int i=0;i<n;i++){
        if(heap->arr[i]==data){
            flag=1;index=i;
        }
    }
    if(flag==0){
        printf("no such elt");return;
    }
    heap->arr[index]=heap->arr[n-1];
    heap->size--;
    n=heap->size;
    heap->arr=realloc(heap->arr,heap->size*sizeof(int));
    if(check==1){
        for(int i=n/2-1;i>=0;i--){
            heapifyMax(maxHeap->arr,i,n);
        }
        printf("max heap: ");
        for(int i=0;i<n;i++){
            printf("%d ",maxHeap->arr[i]);
        }
        printf("\n");
    }
    else{
        for(int i=n/2-1;i>=0;i--){
            heapifyMin(minHeap->arr,i,n);
        }    
        printf("min heap: ");
        for(int i=0;i<n;i++){
            printf("%d ",minHeap->arr[i]);
        }
        printf("\n"); 
    }
}

int main(){
    int a[7]={3,5,2,7,4,9,1};
    createMax(a,7);
    createMin(a,7);
    insert(maxHeap,0,1);
    insert(minHeap,0,2);
    delete(maxHeap,4,1);
    delete(minHeap,4,2);
}

