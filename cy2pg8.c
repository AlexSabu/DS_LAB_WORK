#include <stdio.h>
#include <stdlib.h>

void heapify(int[],int,int);
int partition(int[],int,int);

void insertionSort(int arr[], int n) {
  int i,j,key;
    for(i=1;i<n;i++){
        key=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

void selectionSort(int arr[], int n) {
    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(arr[min]>arr[j]){
                min=j;
            }
        }
        int temp=arr[min];
        arr[min]=arr[i];
        arr[i]=temp;
    }
}

void heapSort(int arr[], int n) {
    for(int i=n/2-1;i>=0;i--){
        heapify(arr,i,n);
    }
    for(int i=n-1;i>0;i--){
        int temp=arr[0];
        arr[0]=arr[i];
        arr[i]=temp;
        heapify(arr,0,i);
    }
}
void heapify(int arr[],int i,int n){
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<n && arr[left]>arr[largest])
        largest=left;
    if(right<n && arr[right]>arr[largest])
        largest=right;
    if(largest!=i){
        int temp=arr[largest];
        arr[largest]=arr[i];
        arr[i]=temp;
        heapify(arr,largest,n);
    } 
}

void merge(int arr[], int l, int m, int r) {
    // Merge Sort helper function for merging two subarrays
    // ...
}

void mergeSort(int arr[], int l, int r) {
    // Merge Sort algorithm implementation
    // ...
}

int partition(int arr[], int low, int high) {
    int i=low,j=high;
    int pivot=arr[low],temp;
    while(i<j){
        while(i<=high && arr[i]<=pivot)
            i++;
        while(j>=low && arr[j]>pivot)
            j--;
        if(i<j){
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    arr[low]=arr[j];
    arr[j]=pivot;
    return j;
}

void quickSort(int arr[], int low, int high) {
    int j;
    if(low<high){
        j=partition(arr,low,high);
        quickSort(arr,low,j);
        quickSort(arr,j+1,high);
    }
}

void printArray(int arr[], int size) {
    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    // Read data from file and populate the array
    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening the file.\n");
        return 1;
    }
    int n;
    fscanf(file,"%d",&n);
    int arr[n];

    for (int i = 0; i < n; i++) {
        fscanf(file, "%d", &arr[i]);
    }
    printf("read array:");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }

    fclose(file);

    int choice;
    printf("\nChoose a sorting algorithm:\n");
    printf("1. Insertion Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Heap Sort\n");
    printf("4. Merge Sort\n");
    printf("5. Quick Sort\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            insertionSort(arr, n);
            break;
        case 2:
            selectionSort(arr, n);
            break;
        case 3:
            heapSort(arr, n);
            break;
        case 4:
            mergeSort(arr, 0, n - 1);
            break;
        case 5:
            quickSort(arr, 0, n - 1);
            break;
        default:
            printf("Invalid choice\n");
            return 1;
    }

    printArray(arr, n);

    return 0;
}
