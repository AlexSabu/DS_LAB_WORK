#include<stdio.h>
#include<stdlib.h>

struct Employee{
    int EmpId;
    char Name[100];
    int Salary;
};

int n;

int search(struct Employee* emp, int key){
    int index;
    for(int i=0;i<n;i++){
        if(emp[i].EmpId==key){
            return i;
        }
    }
    return -1;
}

void main(){
    int key,index;
    printf("Enter n:");scanf("%d",&n);
    struct Employee *emp=(struct Employee*)malloc(n*sizeof(struct Employee));
    printf("enter details:\n");
    for(int i=0;i<n;i++){
        printf("id:");scanf("%d",&emp[i].EmpId);
        getchar();
        printf("full name:");scanf("%[^\n]",&emp[i].Name);
        printf("salary:");scanf("%d",&emp[i].Salary);
    }
    printf("key: ");scanf("%d",&key);
    index=search(emp,key);
    if(index!=-1){
        printf("at %d,\n %d, %s, %d",index+1,emp[index].EmpId,emp[index].Name,emp[index].Salary);
    }
    else{printf("absent");}
    free(emp);
}