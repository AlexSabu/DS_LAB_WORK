

// struct Graph* createGraph(int vertices){
//     struct Graph* graph=(struct Graph*)malloc((sizeof(struct Graph)));
//     graph->vertex=vertices;
//     //array of adjLists
//     graph->adjList=(struct Node**)malloc(vertices*sizeof(struct Node*));
//     //initializing each adjList to null
//     for(int i=0;i<vertices;i++){
//         graph->adjList[i]=NULL;
//     }
//     return graph;
// }

// void insertGraph(int data,int key){
//     struct Node *new=createNode(data);
//     struct Node *current=graph->adjList[key],*temp=NULL;
//     if(current==NULL){
//         graph->adjList[key]=new;
//         return;
//     }
//     while(current!=NULL){
//         temp=current;
//         current=current->link;
//     }
//     temp->link=new;
// }

// void displayGraph(){
//     for(int i=0;i<5;i++){
//         printf("%d: -> ",i);
//         struct Node *current=graph->adjList[i];
//         while(current!=NULL){
//             printf("%d -> ",current->data);
//             current=current->link;
//         }
//         printf("NULL\n");
//     }
// }
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *link;
};

struct Graph{
    int vertex;
    struct Node **adjList;
};
struct Graph *graph;

struct Node* createNode(int data){
    struct Node* new=(struct Node*)malloc(sizeof(struct Node));
    new->data=data;
    new->link=NULL;
    return new;
}

struct Graph* createGraph(int v){
    struct Graph *G=(struct Graph*)malloc(sizeof(struct Graph));
    G->vertex=v;
    G->adjList=(struct Node**)malloc(v*sizeof(struct Node*));
    for(int i=0;i<v;i++){
        G->adjList[i]=NULL;
    }
    return G;
}

struct Graph* insertEdge(struct Graph *G, int src, int dest) {
    // Insert edge from src to dest
    struct Node *current1 = G->adjList[src], *temp1 = NULL;
    if (current1 == NULL) {
        struct Node *new = createNode(dest);
        G->adjList[src] = new;
    } else {
        while (current1 != NULL && current1->data != dest) {
            temp1 = current1;
            current1 = current1->link;
        }
        if (current1 == NULL) {
            struct Node *new = createNode(dest);
            temp1->link = new;
        }
    }

    // Insert edge from dest to src
    struct Node *current2 = G->adjList[dest], *temp2 = NULL;
    if (current2 == NULL) {
        struct Node *new = createNode(src);
        G->adjList[dest] = new;
    } else {
        while (current2 != NULL && current2->data != src) {
            temp2 = current2;
            current2 = current2->link;
        }
        if (current2 == NULL) {
            struct Node *new = createNode(src);
            temp2->link = new;
        }
    }
    return G;
}

struct Graph* deleteEdge(struct Graph *G,int src,int dest){
    // src -> dest edge
    struct Node *current=G->adjList[src];
    struct Node *temp=NULL;
    if(current==NULL){
        printf("no such edge\n");
    }
    else{
        while(current!=NULL && current->data!=dest){
            temp=current;
            current=current->link;
        }
        if(current==NULL){//edge is absent
            printf("no such edge\n");
        }
        else{//edge is there
            if(temp==NULL){
                G->adjList[src]=current->link;
                current->link=NULL;
                free(current);
            }
            else{
                temp->link=current->link;
                current->link=NULL;
                free(current);
            }

        }
    }
    return G;
}

void display(struct Graph *G){
    printf("graph: \n");
    int n=G->vertex;
    for(int i=0;i<n;i++){
        struct Node *current=G->adjList[i];
        printf("%d:-> ",i);
        while(current!=NULL){
            printf("%d -> ",current->data);
            current=current->link;
        }
        printf("NULL\n");
    }
}

int main(){
    graph=createGraph(5);
    insertEdge(graph,0,1);
    insertEdge(graph,0,4);
    insertEdge(graph,1,4);
    insertEdge(graph,3,4);
    insertEdge(graph,2,3);
    insertEdge(graph,1,0);                    
    display(graph);
    deleteEdge(graph,0,1);
    display(graph);
    deleteEdge(graph,0,3);  
    display(graph);   
}
