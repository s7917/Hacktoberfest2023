#include <iostream>
#include <vector>
#include <limits.h>

const int V = 6; // Number of vertices

int minDistance(int dist[], bool visited[]) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
        if (!visited[v] && dist[v] <= min)
            min = dist[v], min_index = v;
    return min_index;
}

void dijkstra(int graph[V][V], int start) {
    int dist[V];
    bool visited[V];

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, visited[i] = false;

    dist[start] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited);
        visited[u] = true;

        for (int v = 0; v < V; v++)
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    std::cout << "Shortest distances from vertex " << start << ":\n";
    for (int i = 0; i < V; i++)
        std::cout << start << " -> " << i << " = " << dist[i] << "\n";
}

int main() {
    int graph[V][V] = {{0, 1, 4, 0, 0, 0},
                       {0, 0, 4, 2, 7, 0},
                       {0, 0, 0, 0, 5, 0},
                       {0, 0, 0, 0, 0, 3},
                       {0, 0, 0, 0, 0, 1},
                       {0, 0, 0, 0, 0, 0}};

    dijkstra(graph, 0);

    return 0;
}
