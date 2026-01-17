#include <stdio.h>
#include <stdlib.h>

int a[20][20], n;
int visited[20];

/* Read graph using adjacency matrix */
void readGraph() {
    int i, j;
    printf("Enter number of vertices:\n");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
}

/* Breadth First Search */
void bfs(int start) {
    int q[20], front = 0, rear = -1;
    int i;

    for (i = 0; i < n; i++)
        visited[i] = 0;

    q[++rear] = start;
    visited[start] = 1;

    printf("BFS Traversal: ");
    while (front <= rear) {
        start = q[front++];
        printf("%d ", start);

        for (i = 0; i < n; i++) {
            if (a[start][i] == 1 && visited[i] == 0) {
                q[++rear] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

/* Depth First Search */
void dfs(int v) {
    int i;
    visited[v] = 1;
    printf("%d ", v);

    for (i = 0; i < n; i++) {
        if (a[v][i] == 1 && visited[i] == 0) {
            dfs(i);
        }
    }
}

int main() {
    int choice, start, i;

    readGraph();

    while (1) {
        printf("\n1.BFS\n2.DFS\n3.Exit\n");
        printf("Enter choice:\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter starting vertex:\n");
                scanf("%d", &start);
                bfs(start);
                break;

            case 2:
                printf("Enter starting vertex:\n");
                scanf("%d", &start);
                for (i = 0; i < n; i++)
                    visited[i] = 0;
                printf("DFS Traversal: ");
                dfs(start);
                printf("\n");
                break;

            case 3:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
}
