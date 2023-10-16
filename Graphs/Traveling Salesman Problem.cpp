#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const int INF = numeric_limits<int>::max();

int tsp(vector<vector<int>>& graph, int start, int mask, vector<vector<int>>& dp) {
    int n = graph.size();

    if (mask == (1 << n) - 1) {
        return graph[start][0];
    }

    if (dp[start][mask] != -1) {
        return dp[start][mask];
    }

    int minCost = INF;

    for (int next = 0; next < n; next++) {
        if ((mask & (1 << next)) == 0 && graph[start][next] != 0) {
            int newMask = mask | (1 << next);
            int cost = graph[start][next] + tsp(graph, next, newMask, dp);
            minCost = min(minCost, cost);
        }
    }

    dp[start][mask] = minCost;
    return minCost;
}

int main() {
    vector<vector<int>> graph = {
        {0, 29, 20, 21},
        {29, 0, 15, 17},
        {20, 15, 0, 28},
        {21, 17, 28, 0}
    };

    int n = graph.size();
    vector<vector<int>> dp(n, vector<int>(1 << n, -1));

    int start = 0;
    int mask = 1; // Start with the first city
    int minCost = tsp(graph, start, mask, dp);

    cout << "Minimum TSP cost: " << minCost << endl;

    return 0;
}
