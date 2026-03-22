// https://takeuforward.org/data-structure/topological-sort-algorithm-dfs-g-21

// dfs approach 

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public: 
    void dfs(int node, vector<int> adj[], vector<int>& vis, stack<int>& st) {
        vis[node] = 1;

        for(auto it: adj[node]) {
            if(!vis[it]) {
                dfs(it, adj, vis, st);
            }
        }

        st.push(node);
    }

    vector<int> topoSort(int v, vector<int> adj[]) {
        vector<int> vis(v, 0);

        stack<int> st;

        for(int i=0; i<v; i++) {
            if(!vis[i]) {
                dfs(i, adj, vis, st);
            }
        }

        vector<int> ans;
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};

int main() {
    int V = 6, E = 6;

    vector<int> adj[V];
    adj[5].push_back(0);
    adj[5].push_back(2);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    Solution obj;

    vector<int> res = obj.topoSort(V, adj);

    cout << "Topological Sort: ";
    for (auto it : res) {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}


/*
complexityy analysis 

time  complexity => o(V + E)
        each vertex and each edge is visited exactly once i the DFS treversal done for topo sorting


space => o(V + E) => this comes from the 3 parts, first the adjacency list which stores all edges and vertices, the visited array , and the recursion srack 
*/