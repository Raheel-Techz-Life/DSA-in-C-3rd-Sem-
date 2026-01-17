#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Queue structure for BFS
struct Queue {
    int items[MAX_VERTICES];
    int front;
    int rear;
};

struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

int isEmpty(struct Queue* q) {
    return q->rear == -1;
}

void enqueue(struct Queue* q, int value) {
    if (q->rear == MAX_VERTICES - 1) {
        printf("Queue is full\n");
    } else {
        if (q->front == -1) {
            q->front = 0;
        }
        q->rear++;
        q->items[q->rear] = value;
    }
}

int dequeue(struct Queue* q) {
    int item;
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        item = -1;
    } else {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear) {
            q->front = q->rear = -1;
        }
    }
    return item;
}

// Graph structure using adjacency matrix
struct Graph {
    int vertices;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
};

// Create a graph
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->vertices = vertices;
    
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph->adjMatrix[i][j] = 0;
        }
    }
    
    return graph;
}

// Add edge
void addEdge(struct Graph* graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 1;
    graph->adjMatrix[dest][src] = 1; // For undirected graph
}

// BFS traversal
void BFS(struct Graph* graph, int startVertex) {
    int visited[MAX_VERTICES] = {0};
    struct Queue* q = createQueue();
    
    visited[startVertex] = 1;
    enqueue(q, startVertex);
    
    printf("BFS Traversal: ");
    
    while (!isEmpty(q)) {
        int currentVertex = dequeue(q);
        printf("%d ", currentVertex);
        
        for (int i = 0; i < graph->vertices; i++) {
            if (graph->adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = 1;
                enqueue(q, i);
            }
        }
    }
    printf("\n");
}

// DFS helper function
void DFSUtil(struct Graph* graph, int vertex, int visited[]) {
    visited[vertex] = 1;
    printf("%d ", vertex);
    
    for (int i = 0; i < graph->vertices; i++) {
        if (graph->adjMatrix[vertex][i] == 1 && !visited[i]) {
            DFSUtil(graph, i, visited);
        }
    }
}

// DFS traversal
void DFS(struct Graph* graph, int startVertex) {
    int visited[MAX_VERTICES] = {0};
    
    printf("DFS Traversal: ");
    DFSUtil(graph, startVertex, visited);
    printf("\n");
}

int main() {
    struct Graph* graph = createGraph(6);
    
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 5);
    addEdge(graph, 4, 5);
    
    BFS(graph, 0);
    DFS(graph, 0);
    
    free(graph);
    return 0;
}
