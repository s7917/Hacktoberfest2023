#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int V = 6;

int graph[V][V] = {
    {0, 16, 13, 0, 0, 0},
    {0, 0, 10, 12, 0, 0},
    {0, 4, 0, 0, 14, 0},
    {0, 0, 9, 0, 0, 20},
    {0, 0, 0, 7, 0, 4},
    {0, 0, 0, 0, 0, 0}
};

bool bfs(int rGraph[V][V], int source, int sink, vector<int>& parent) {
    vector<bool> visited(V, false);
    queue<int> q;
    q.push(source);
    visited[source] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < V; v++) {
            if (!visited[v] && rGraph[u][v] > 0) {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }

    return visited[sink];
}

int fordFulkerson(int source, int sink) {
    int rGraph[V][V];
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            rGraph[i][j] = graph[i][j];
        }
    }

    vector<int> parent(V, -1);
    int maxFlow = 0;

    while (bfs(rGraph, source, sink, parent)) {
        int pathFlow = INT_MAX;
        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            pathFlow = min(pathFlow, rGraph[u][v]);
        }

        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            rGraph[u][v] -= pathFlow;
            rGraph[v][u] += pathFlow;
        }

        maxFlow += pathFlow;
    }

    return maxFlow;
}

int main() {
    int source = 0;
    int sink = 5;
    int maxFlow = fordFulkerson(source, sink);

    cout << "Maximum Flow: " << maxFlow << endl;

    return 0;
}
