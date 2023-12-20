#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void sort(string s[],int n){
    char temp[100];
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(strcmp(s[j].str,s[j+1].str)>0){
                strcpy(temp,s[j].str);
                strcpy(s[j].str,s[j+1].str);
                strcpy(s[j+1].str,temp);
            }
        }

    }
}

int bsearch(){

}


typedef struct {
    char str[100];
}string;

string s[100];

void main(){
    FILE *file;
    char filename[100];
    int n=0;
    printf("enter filename:");scanf("%s",&filename);
    file=fopen(filename,"r");
    if(file==NULL){
        printf("cannot open file");
        exit(0);
    }
    while(n<100){
        fgets(s[n].str,100,file);
        if(s[n].str[strlen(s[n].str)-1]=='\n'){
            s[n].str[strlen(s[n].str)-1]='\0';
        }
        if(s[n].str==NULL){
            break;
        }
    }
    fclose(file);
    sort(s,n);

    printf("sorted strings:\n");
    for(int i=0;i<n;i++){
        printf("%s\n",s[n].str);
    }
}