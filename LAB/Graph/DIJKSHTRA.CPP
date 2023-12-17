#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V 100

// Function prototypes
int minDistance(int dist[], int sptSet[]);
void printSolution(int dist[], int n);

// Function to find the vertex with the minimum distance value, from the set of vertices not yet included in the shortest path tree
int minDistance(int dist[], int sptSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == 0 && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

// A utility function to print the constructed distance array
void printSolution(int dist[], int n) {
    printf("Shortest distances from source:\n");
    for (int i = 0; i < n; i++)
        printf("%d: %d\n", i, dist[i]);
}

// Function to implement Dijkstra's algorithm for a given graph represented using adjacency matrix
void dijkstra(int graph[V][V], int src) {
    int dist[V]; // The output array dist[i] holds the shortest distance from src to i
    int sptSet[V]; // sptSet[i] is true if vertex i is included in the shortest path tree or the shortest distance from src to i is finalized

    // Initialize all distances as INFINITE and sptSet[] as false
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = 0;

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not yet processed.
        int u = minDistance(dist, sptSet);

        // Mark the picked vertex as processed
        sptSet[u] = 1;

        // Update dist value of the adjacent vertices of the picked vertex
        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    // Print the constructed distance array
    printSolution(dist, V);
}

int main() {
    int graph[V][V];
    int vertices, edges;

    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &vertices, &edges);

    // Initialize the graph with INF distances
    for (int i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++)
            graph[i][j] = (i == j) ? 0 : INT_MAX;

    // Input edges and weights
    for (int i = 0; i < edges; i++) {
        int u, v, w;
        printf("Enter edge and weight (u v w): ");
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
    }

    // Input the source vertex
    int source;
    printf("Enter the source vertex: ");
    scanf("%d", &source);

    dijkstra(graph, source);

    return 0;
}
