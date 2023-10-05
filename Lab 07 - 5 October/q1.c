// Given an undirected weighted connected graph G(V, E) and starring vertex ‘s’. Maintain a Min-Priority Queue ‘Q’ from the vertex set V and apply Prim’s algorithm to  Find the minimum spanning tree T(V, E’). Display the cost adjacency matrix of ‘T’.  Display total cost of the minimum spanning tree T. Note# Nodes will be numbered consecutively from 1 to n (user input), and edges will have varying weight. The graph G can be read from an input file “inUnAdjMat.dat” that contains cost adjacency matrix. The expected output could be displayed as the cost adjacency matrix of the minimum spanning tree and total cost of the tree.

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main()
{
    FILE *fp = fopen("inUnAdjMat.dat", "r");
    if (fp == NULL)
    {
        printf("Error opening file\n");
        exit(0);
    }
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    int adjMat[n][n];
    printf("Enter the starting vertex: ");
    int s;
    scanf("%d", &s);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fscanf(fp, "%d", &adjMat[i][j]);
        }
    }

    int visited[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
    visited[s] = 1;

    int totalWeight = 0;
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 1)
        {
            for (int j = 0; j < n; j++)
            {
                if (visited[j] == 0)
                {
                    if (adjMat[i][j] != 0)
                    {
                        totalWeight += adjMat[i][j];
                        visited[j] = 1;
                    }
                }
            }
        }
    }

    // print the visited elements as a matrix and print 0 if not visited
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(visited[i] == 1 && visited[j] == 1){
                printf("%d ", adjMat[i][j]);
            }
            else{
                printf("0 ");
            }
        }
        printf("\n");
    }

    

    printf("Total weight of the spanning Tree: %d\n", totalWeight);
}