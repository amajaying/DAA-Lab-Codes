// Aim of the program: Given an undirected weighted connected graph G(V, E) and
// starring vertex ‘s’. Maintain a Min-Priority Queue ‘Q’ from the vertex set V and
// apply Prim’s algorithm to
//  Find the minimum spanning tree T(V, E’). Display the cost adjacency matrix
// of ‘T’.
//  Display total cost of the minimum spanning tree T.
// Note# Nodes will be numbered consecutively from 1 to n (user input), and edges will
// have varying weight. The graph G can be read from an input file “inUnAdjMat.dat”
// that contains cost adjacency matrix. The expected output could be displayed as the
// cost adjacency matrix of the minimum spanning tree and total cost of the tree.

// Content of the input file “inUnAdjMat.dat”

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(){
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    int s;
    printf("Enter the starting vertex: \n");
    scanf("%d", &s);
    int adj[n][n];

    FILE *fp;
    fp = fopen("inUnAdjMat.dat", "r");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            fscanf(fp, "%d ", &adj[i][j]);
        }
    }
    fclose(fp);

    int Q[n];
    for(int i=0; i<n; i++){
        Q[i] = INT_MAX;
    }
    Q[s-1] = 0;

    int parent[n];
    for(int i=0; i<n; i++){
        parent[i] = -1;
    }

    int visited[n];
    for(int i=0; i<n; i++){
        visited[i] = 0;
    }

    int u;

    while(1){
        int min = INT_MAX;
        for(int i=0; i<n; i++){
            if(Q[i] < min && visited[i] == 0){
                min = Q[i];
                u = i;
            }
        }
        if(min == INT_MAX){
            break;
        }
        visited[u] = 1;
        for(int v=0; v<n; v++){
            if(adj[u][v] != 0 && visited[v] == 0 && adj[u][v] < Q[v]){
                Q[v] = adj[u][v];
                parent[v] = u;
            }
        }
    }

    printf("The cost adjacency matrix of T is: \n");

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(parent[i] == j || parent[j] == i){
                printf("%d ", adj[i][j]);
            }
            else{
                printf("0 ");
            }
        }
        printf("\n");
    }


    int totalCost = 0;
    for(int i=0; i<n; i++){
        if(parent[i] != -1){
            totalCost += adj[i][parent[i]];
        }
    }
    printf("The total cost of T is: %d\n", totalCost);

    return 0;

    
}

