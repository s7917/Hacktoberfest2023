//A C++ Program to Calculate the Minimum_Height_Trees
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        // Handle special cases for n = 0, 1, and 2.
        if (n == 0) return {};
        if (n == 1) return {0};
        if (n == 2) return {0, 1};

        // Create an adjacency list to represent the graph and initialize the degree of each node.
        vector<vector<int>> graph(n);
        vector<int> degree(n, 0);
        vector<int> res;

        // Populate the graph and update node degrees.
        for (auto &edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
            degree[edge[0]]++;
            degree[edge[1]]++;
        }

        // Create a queue to perform topological sorting.
        queue<int> q;

        // Initialize the queue with leaf nodes (degree = 1).
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) {
                q.push(i);
            }
        }

        // Perform topological sorting until we reach the MHT roots.
        while (!q.empty()) {
            res.clear();  // Clear the previous level of leaf nodes.
            int sz = q.size();

            // Process all nodes at the current level.
            while (sz--) {
                int u = q.front();
                q.pop();
                res.push_back(u);

                // Update the degree of neighboring nodes.
                for (auto v : graph[u]) {
                    if (--degree[v] == 1) {
                        q.push(v);
                    }
                }
            }
        }
        return res;  // The roots of the MHT.
    }
};
