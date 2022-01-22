#include<stdio.h>

typedef struct Node {
    struct Node *next;
    int data;
}Node;

typedef struct Graph{
    int visited[20];
    Node *edges[20];
}Graph;



Graph* createGraph(Graph *g , int vertices_count){
    int i=0 , j=0 ;
    int num_edges;
    int edge_to;

    for (i=0; i<vertices_count; i++){
         printf("Enter no of edges for vertex %d : " , i);
         scanf("%d" , &num_edges);
         Node *v = (Node *)malloc(sizeof(Node));
         v->data = i;
         v->next=NULL;
         g->edges[i]=v;
         g->visited[i] = 0;
         for(j=0;j<num_edges;j++){
            Node *to = (Node *)malloc(sizeof(Node));
            printf("Enter edge from %d to : " , i);
            scanf("%d" , &edge_to);
            to->data = edge_to;
            to->next=NULL;
            while(v->next!=NULL){
                v=v->next;
            }
            v->next = to;
         }
    }
    return g;

}

void displayGraph(Graph* graph, int num_vertices) {
  int v;
  for (v = 0; v < num_vertices; v++) {
    Node* temp = graph->edges[v];
    printf("\n Vertex %d\n: ", v);
    while (temp) {
        if(temp->next==NULL){
            printf("%d -> NULL" , temp->data);
        }else{
             printf("%d -> ", temp->data);
        }

      temp = temp->next;
    }
    printf("\n");
  }
}

void DFS(Graph *g , int vertex){
    Node* temp = g->edges[vertex];
  g->visited[vertex] = 1;
  printf("Visited %d \n", vertex);

  while (temp != NULL) {
    int connectedVertex = temp->next->data;
    if (g->visited[connectedVertex] == 0) {
      DFS(g, connectedVertex);
    }
    temp = temp->next;
  }

}



void main(){
    Graph* g = (Graph *)malloc(sizeof(Graph));
    int num_vertices = 0;
    printf("Enter no of vertices : ");
    scanf("%d" , &num_vertices);
    g = createGraph(g , num_vertices);
    displayGraph(g , num_vertices);
    printf("\n DFS \n");
    DFS(g , 0);

}
