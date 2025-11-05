// https://takeuforward.org/data-structure/detect-a-cycle-in-a-directed-graph

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isCyclic(int V, vector<vector<int>>& adj) {
        vector<int> indegree(V, 0);

        for (int i = 0; i < V; i++) {
            for (auto &nbr : adj[i]) {
                indegree[nbr]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        int count = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            count++;

            for (auto &nbr : adj[node]) {
                indegree[nbr]--;

                if (indegree[nbr] == 0)
                    q.push(nbr);
            }
        }

        return count != V;
    }
};

int main() {
    int V = 4;

    vector<vector<int>> adj = {
        {1}, {2}, {3}, {1}  
    };

    Solution sol;

    cout << (sol.isCyclic(V, adj) ? "Graph contains a cycle" : "No cycle") << endl;

    return 0;
}