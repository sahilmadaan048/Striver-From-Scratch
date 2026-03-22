#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int> adjRev[V];  // Reverse adjacency list
        int indegree[V] = {0};  // Indegree array to track nodes with no outgoing edges

        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                adjRev[it].push_back(i);  // Reverse the direction of edges
                indegree[i]++;  // Increment indegree for the current node
            }
        }

        queue<int> q;  // Queue to store nodes with no outgoing edges (safe nodes)
        vector<int> safeNodes;

        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);  // This node is safe
            for (auto it : adjRev[node]) {
                indegree[it]--;  // Decrease indegree of the parent nodes
                if (indegree[it] == 0) {
                    q.push(it);  // If indegree becomes 0, it is a safe node
                }
            }
        }

        sort(safeNodes.begin(), safeNodes.end());  // Sort the safe nodes
        return safeNodes;
    }
};

int main() {
    vector<int> adj[12] = {{1}, {2}, {3, 4}, {4, 5}, {6}, {6}, {7}, {}, {1, 9}, {10},
                           {8}, {9}};
    int V = 12;  // Number of nodes in the graph

    Solution obj;

    for (auto node : safeNodes) {
        cout << node << " ";  // Print the safe nodes
    }
    cout << endl;

    return 0;
}

/*
Complexity Analysis

Time Complexity: O(V + E) + O(N log N),

O(V + E) for performing BFS on the graph (where V = number of vertices/nodes, E = number of edges).
O(N log N) for sorting the safeNodes array (where N is the number of safe nodes).

Space Complexity: O(3N) ~ O(N),

O(N) for the indegree array.
O(N) for the queue used during BFS traversal.
O(N) for the reversed adjacency list representation of the graph.

*/