//graph
#include<stdio.h>
#include<stdlib.h>

//node in an adjacency list
struct Node{
    int data;
    struct Node *link;
};

//graph using adjList
struct Graph{
    int vertices;
    struct Node **adjList;
};

void DFS_rec(struct Graph *graph,int vertex,int visited[]);

//creating nodes of adjList
struct Node* createNode(int data){
    struct Node* new=(struct Node*)malloc(sizeof(struct Node));
    new->data=data;
    new->link=NULL;
    return new;
}

//create a graph using no. of vertices
struct Graph* createGraph(int vertices){
    struct Graph* graph=(struct Graph*)malloc((sizeof(struct Graph)));
    graph->vertices=vertices;
    //array of adjLists
    graph->adjList=(struct Node**)malloc(vertices*sizeof(struct Node*));
    //initializing each adjList to null
    for(int i=1;i<=vertices;i++){
        graph->adjList[i]=NULL;
    }
    return graph;
}

//adding an edge to an undirected graph
void addEdge(struct Graph *graph,int src,int dest){
    //edge from src to dest
    struct Node *new=createNode(dest);
    new->link=graph->adjList[src];
    graph->adjList[src]=new;
    //edge from dest to src
    new=createNode(src);
    new->link=graph->adjList[dest];
    graph->adjList[dest]=new;
}

//print adjacency list
void printAdjList(struct Graph* graph){
    printf("adjacency list: \n");
    for(int i=1;i<=graph->vertices;i++){
        printf("vertex-%d: ",i);
        struct Node *current=graph->adjList[i];
        while(current){
            printf("%d ",current->data);
            current=current->link;
        }
        printf("\n");
    }
    
}

//print adjacency matrix
void printAdjMatrix(struct Graph *graph){
    printf("adjacency matrix: \n");
    for(int i=1;i<=graph->vertices;i++){
        for(int j=1;j<=graph->vertices;j++){
            int check=0;
            struct Node *current=graph->adjList[i];
            while(current!=NULL){
                if(current->data==j){
                    check=1;
                    break;
                }
                current=current->link;
            }
            printf("%d ",check);
        }
        printf("\n");
    }
}

//depth first search
void DFS(struct Graph *graph,int firstVertex){
    //visited array
    int* visited=(int*)malloc((graph->vertices +1)*(sizeof(int)));
    for(int i=1;i<=graph->vertices;i++){
        visited[i]=0;
    }
    DFS_rec(graph,firstVertex,visited);
    printf("\n");
    free(visited);
}
void DFS_rec(struct Graph *graph,int vertex,int visited[]){
    visited[vertex]=1;
    printf("%d ",vertex);
    struct Node *current=graph->adjList[vertex];
    while(current){
        if(visited[current->data]==0){
            DFS_rec(graph,current->data,visited);
        }
        current=current->link;
    }
}


void main(){
    int vertices,edges;
    printf("no. of vertices and edges: ");
    scanf("%d %d",&vertices,&edges);
    struct Graph *graph=createGraph(vertices);
    printf("enter source & destination: \n");
    for(int i=0;i<edges;i++){
        printf("edge-%d: ",i+1);
        int src,dest;
        scanf("%d %d",&src,&dest);
        addEdge(graph,src,dest);
    }
    printAdjList(graph);
    printAdjMatrix(graph);
    int start;
    printf("starting vertex: ");scanf("%d",&start);
    printf("depth first search: \n");
    DFS(graph,start);
    printf("breadth first search: \n");
    DFS(graph,start);
}