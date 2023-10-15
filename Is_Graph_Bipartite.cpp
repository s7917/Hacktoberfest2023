//A C++ Program to check if Graph is Bipartite.
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size(); // Get the number of nodes in the graph.
        vector<int> adj[n]; 

        // Convert the input adjacency list to the adjacency list representation.
        for (int i = 0; i < n; i++) {
            for (auto x : graph[i]) {
                adj[i].push_back(x);
            }
        }

        vector<int> colored(n, -1); // Initialize a color array for nodes.

        for (int i = 0; i < n; i++) {
            if (colored[i] == -1) {
                // Start a BFS traversal from uncolored nodes.
                queue<pair<int, int>> q; // Use a queue to perform BFS. Each element is {node, color}.
                q.push({i, 0}); 
                colored[i] = 0; 

                while (!q.empty()) {
                    int node = q.front().first;
                    int color = q.front().second;
                    q.pop();

                    for (auto x : adj[node]) {
                        // Check each neighbor of the current node.
                        // If the neighbor is not colored, color it with the opposite color and add it to the queue.
                        if (colored[x] == -1) {
                            colored[x] = !color;
                            q.push({x, colored[x]});
                        }
                        // If the neighbor has the same color as the current node, the graph is not bipartite.
                        else if (colored[x] == color) {
                            return false;
                        }
                    }
                }
            }
        }

        // If the BFS traversal completes without conflicts (same-colored neighbors), the graph is bipartite.
        return true;
    }
};
