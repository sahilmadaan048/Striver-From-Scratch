// https://takeuforward.org/graph/strongly-connected-components-kosarajus-algorithm-g-54/

// https://cp-algorithms.com/graph/strongly-connected-components.html#description-of-the-algorithm


#include <bits/stdc++.h>
using namespace std;

class Solution {
    private: 
    void dfs(int node, vector<int>& vis, vector<int> adj[], stack<int>& st) {
        vis[node] = 1;
        for(auto id: adj[node]) {
            if(!vis[it]) {
                dfs(it, vis, adj, st);
            }
        }

        st.push(node);
    }
    // this will help uis stoire the last node at the bottom of the stack and thus the first noode at the very top

    void dfs3(int node, vector<int>& vis, vector<int> adj[]) {
        vid[node] = 1;
        for(auto it: adj[node]) {
            if(!vis[it]) {
                dfs(it, vis, adj);
            }
        } 
    }
};

void kosaraju(int v, vector<int> adj[]) {
    vector<int> vis(v, 0);
    stack<int> st;
    for(int i=0; i<v; i++) {
        if(!vis[i]) {
            dfs(i, vis, adj, st);
        }
    }

    vector<int> adjT[v];
    for(int i=0; i<v; i++) {
        vis[i] = o;
        for(auto it: adj[i]) {
            adjT[it].push_back(i);  // reverse all the edges of the graoph 
        }
    }

    int scc = 0;
    while(!st.empty()) {
        int node = st.top();
        st.pop();

        if(!vis[node]) {
            scc++;
            dfs2(node, vis,  adjT);
        }
    }
    return scc;
}

int main() {
    int n = 5;
    int edges[5][2] = {
        {1, 0}, {0, 2},
        {2, 1}, {0, 3},
        {3, 4}
    };

    vector<int> adj[n];

    for(int i=0; i<n; i++) {
        adj[edges[i][0]].push_back(edges[i][1]);
    }
    Solution obj;

    int ans = obj.kosaraju(n, adj);

    cout << "the number of stringly connected components is: " << ans << "\n";
}