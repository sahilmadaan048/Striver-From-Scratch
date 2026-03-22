// https://takeuforward.org/data-structure/topological-sort-algorithm-dfs-g-21

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> topologicalSort(int V, vector<int> adj[])
    {
        vector<int> indegree(V, 0);

        for(int i=0; i<V; i++) {
            for(auto it: adj[i]) {
                indegree[it]++;
            }
        }
        queue<int> q;

        for(int i=0; i<V; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> topo;

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            topo.push_back(node);

            for(auto it: adj[node]) {
                indegree[it]--;
                if(indegree[it] == 0) {
                    q.push(it);
                }
            }
        }
        return topo;
    }
};

int main()
{
    int V = 6, E = 6;
    vector<int> adj[V];

    adj[5].push_back(0);
    adj[5].push_back(2);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    Solution obj;
    vector<int> ans = obj.topologicalSort(V, adj);

    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}

/*
complexity analysis

Time Complexity: O(V + E) because we visit each vertex exactly once and process all outgoing edges from each vertex exactly once. The in-degree calculation takes O(E), and each vertex is enqueued and dequeued exactly once in O(V). Thus, total time is linear in the sum of vertices and edges.

Space Complexity: O(V + E) because we store the adjacency list which takes O(E) space, the in-degree array which takes O(V), the queue which can store up to O(V) vertices at a time, and the topological order array which takes O(V). Overall, the space requirement is proportional to the size of the graph.
*/