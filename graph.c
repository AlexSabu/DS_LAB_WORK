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
    // dest -> src edge
    struct Node *current1=G->adjList[dest];
    struct Node *temp1=NULL;
    if(current1==NULL){
        printf("no such edge\n");
    }
    else{
        while(current1!=NULL && current1->data!=src){
            temp1=current1;
            current1=current1->link;
        }
        if(current1==NULL){//edge is absent
            printf("no such edge\n");
        }
        else{//edge is there
            if(temp1==NULL){
                G->adjList[dest]=current1->link;
                current1->link=NULL;
                free(current1);
            }
            else{
                temp1->link=current1->link;
                current1->link=NULL;
                free(current1);
            }
        }
    }
    return G;
}



void DFS(int start){
    int* visited=(int*)malloc(graph->vertex*sizeof(int));
    for(int i=0;i<graph->vertex;i++){
        visited[i]=0;//unvisited state
    }
    printf("DFS: ");
    DFS_rec(start,visited);
    free(visited);
    printf("\n");
}

//BFS 
void BFS(int start){
    int* visited=(int*)malloc(graph->vertex*sizeof(int));
    for(int i=0;i<graph->vertex;i++){
        visited[i]=0;//unvisited state
    }
    printf("BFS: ");
    int* queue=(int*)malloc(graph->vertex*sizeof(int));
    int front=-1,rear=-1;
    visited[start]=1;
    queue[++rear]=start;

    while(front!=rear){
        int vertex=queue[++front];
        printf("%d ->",vertex);
        struct Node *current=graph->adjList[vertex];        
        while(current!=NULL){
            int neighbour=current->data;
            if(visited[neighbour]==0){
                visited[neighbour]=1;
                queue[++rear]=neighbour;
            }
            current=current->link;
        }
    }
    free(visited);
    free(queue);
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
    graph=createGraph(8);
    insertEdge(graph,0,1);
    insertEdge(graph,1,2);
    insertEdge(graph,1,7);
    insertEdge(graph,2,4);
    insertEdge(graph,2,3);
    insertEdge(graph,4,5);                    
    insertEdge(graph,4,6);
    insertEdge(graph,4,7);
    display(graph);   

    DFS(0);//start at 0
    BFS(0);
}
