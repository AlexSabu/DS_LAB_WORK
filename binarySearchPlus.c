#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char string[100][100];//stores all strings from file
int count=0;//stores total count of strings in file

void sort(){//sort function
    char temp[100];
    for(int i=0;i<count;i++){
        for(int j=0;j<count-i-1;j++){
            if(strcmp(string[j],string[j+1])>0){
                strcpy(temp,string[j]);
                strcpy(string[j],string[j+1]);
                strcpy(string[j+1],temp);
            }
        }
    }
}
void binarySearch(){
    char key[100];
    int l=0,r=count-1,mid=(l+r)/2;
    printf("enter key: ");scanf("%s",key);
    while(l<=r){
        mid=(l+r)/2;
        if(strcmp(string[mid],key)==0){
            printf("%s found at line %d\n",string[mid],mid+1);
            return;
        }
        else if(strcmp(string[mid],key)>0){
            r=mid-1;
            mid=(l+r)/2;
        }
        else{
            l=mid+1;
            mid=(l+r)/2;
        }
    }
    printf("string absent in file");
}


int main(){
    char str[100];//stores each string read from file
    FILE *fptr;
    char filename[50];
    printf("Enter filename: ");scanf("%s",filename);
    fptr=fopen(filename,"r");
    if(fptr==NULL){
        printf("file does not exist");return 1;
    }
    while(fgets(str,sizeof(str),fptr)!=NULL){
        /*int len=0;
        while(str[len]!="\n"){
            len++;
        }
        str[len]='\0';*/
        str[strcspn(str,"\n")]='\0';
        strcpy(string[count],str);
        count++;
    }
    fclose(fptr);
    sort();
    printf("sorted name order:\n");
    for(int i=0;i<count;i++){
        printf("%s\n",string[i]);
    }
    binarySearch();
}