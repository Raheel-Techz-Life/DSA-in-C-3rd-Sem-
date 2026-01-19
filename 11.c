#include <stdio.h>

int a[10][10], n;
int s[10];   // visited array

void bfs(int a[10][10], int n, int u)
{
    int v, q[10], f = 0, r = -1;

    for (v = 0; v < n; v++)
        s[v] = 0;

    printf("%d ", u);
    s[u] = 1;
    q[++r] = u;

    while (f <= r)
    {
        u = q[f++];

        for (v = 0; v < n; v++)
        {
            if (a[u][v] == 1 && s[v] == 0)
            {
                printf("%d ", v);
                s[v] = 1;
                q[++r] = v;
            }
        }
    }
}

void dfs(int u)
{
    int v;
    s[u] = 1;
    printf("%d ", u);

    for (v = 0; v < n; v++)
    {
        if (a[u][v] == 1 && s[v] == 0)
            dfs(v);
    }
}

int main()
{
    int i, j, source, choice;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter source vertex: ");
    scanf("%d", &source);

    while (1)
    {
        printf("\n1. DFS\n2. BFS\n3. Exit\nEnter choice: ");
        scanf("%d", &choice);

        for (i = 0; i < n; i++)
            s[i] = 0;

        switch (choice)
        {
        case 1:
            printf("DFS Traversal: ");
            dfs(source);
            printf("\n");
            break;

        case 2:
            printf("BFS Traversal: ");
            bfs(a, n, source);
            printf("\n");
            break;

        case 3:
            return 0;

        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}
