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
