// https://takeuforward.org/data-structure/detect-a-cycle-in-directed-graph-topological-sort-kahns-algorithm-g-23

// https://leetcode.com/problems/course-schedule/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool hasCycle(int V, vector<vector<int>> &adj)
    {
        vector<int> indegree(V, 0);
        for (int u = 0; u < V; u++)
        {
            for (int v : adj[u])
            {
                indegree[v]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        int count = 0; // count the vioisited nodes
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            count++;
            for (int it : adj[node])
            {
                indegree[it]--;
                if (indegree[it] == 0)
                {
                    q.push(it);
                }
            }
        }
        return count != V;
    }
};

int main()
{
    int V = 4;
    vector<vector<int>> adj = {
        {1}, {2}, {3}, {1}};

    Solution obj;
    if (obj.hasCycle(V, adj))
        cout << "Cycle detected\n";
    else
        cout << "No cycle\n";
    return 0;
}

/*

kahns aglgo => bfs se topo sort nikalna


Complexity Analysis

Time Complexity: O(V+E), we traverse all the edges and visit all the vertices once.

Space Complexity: O(V+E), additonal space is used to store adjacency list, in-degree array and vertices in queue.

*/