#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main()
{
    int n, m;
    printf("Enter number of nodes & edges: ");
    scanf("%d", &n);
    scanf("%d", &m);
    int adj[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            adj[i][j] = 0;
        }
    }
    int u, v, w;
    for (int i = 0; i < m; i++)
    {
        printf("Enter the edge and weight: ");
        scanf("%d %d %d", &u, &v, &w);
        adj[u - 1][v - 1] = w;
        adj[v - 1][u - 1] = w;
    }

    int Q[n];
    for (int i = 0; i < n; i++)
    {
        Q[i] = INT_MAX;
    }
    Q[0] = 0;

    int parent[n];
    for (int i = 0; i < n; i++)
    {
        parent[i] = -1;
    }

    int visited[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    while (1)
    {
        int min = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (Q[i] < min && visited[i] == 0)
            {
                min = Q[i];
                u = i;
            }
        }
        if (min == INT_MAX)
        {
            break;
        }
        visited[u] = 1;
        for (int i = 0; i < n; i++)
        {
            if (adj[u][i] != 0 && visited[i] == 0 && adj[u][i] < Q[i])
            {
                Q[i] = adj[u][i];
                parent[i] = u;
            }
        }
    }

    int cost = 0;
    for (int i = 0; i < n; i++)
    {
        cost += Q[i];
    }
   
    for (int i = 0; i < n; i++)
    {
        if (parent[i] != -1)
        {
            printf("%d---%d %d\n", i + 1, parent[i] + 1, adj[i][parent[i]]);
        }
    }

     printf("\nTotal weight of the Spanning Tree: %d\n", cost);
    return 0;
}