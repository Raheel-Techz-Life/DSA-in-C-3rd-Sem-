#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

struct Queue {
    int items[MAX_VERTICES];
    int front;
    int rear;
};

void initQueue(struct Queue* q) {
    q->front = -1;
    q->rear = -1;
}

bool isQueueEmpty(struct Queue* q) {
    return q->front == -1;
}

void enqueue(struct Queue* q, int value) {
    if (q->rear == MAX_VERTICES - 1) return;
    if (q->front == -1) q->front = 0;
    q->items[++q->rear] = value;
}

int dequeue(struct Queue* q) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    int item = q->items[q->front];
    if (q->front >= q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    return item;
}

void DFS(int graph[][MAX_VERTICES], int vertices, int start, bool visited[]) {
    visited[start] = true;
    printf("%d ", start);
    
    for (int i = 0; i < vertices; i++) {
        if (graph[start][i] == 1 && !visited[i]) {
            DFS(graph, vertices, i, visited);
        }
    }
}

void BFS(int graph[][MAX_VERTICES], int vertices, int start) {
    bool visited[MAX_VERTICES] = {false};
    struct Queue q;
    initQueue(&q);
    
    visited[start] = true;
    enqueue(&q, start);
    
    while (!isQueueEmpty(&q)) {
        int current = dequeue(&q);
        printf("%d ", current);
        
        for (int i = 0; i < vertices; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                visited[i] = true;
                enqueue(&q, i);
            }
        }
    }
}

int main() {
    int vertices = 5;
    int graph[MAX_VERTICES][MAX_VERTICES] = {0};
    
    graph[0][1] = graph[1][0] = 1;
    graph[0][2] = graph[2][0] = 1;
    graph[1][3] = graph[3][1] = 1;
    graph[1][4] = graph[4][1] = 1;
    graph[2][4] = graph[4][2] = 1;
    
    printf("Graph Traversal Demo\n");
    printf("===================\n\n");
    
    bool visited[MAX_VERTICES] = {false};
    printf("DFS Traversal starting from vertex 0: ");
    DFS(graph, vertices, 0, visited);
    printf("\n");
    
    printf("BFS Traversal starting from vertex 0: ");
    BFS(graph, vertices, 0);
    printf("\n");
    
    return 0;
}
