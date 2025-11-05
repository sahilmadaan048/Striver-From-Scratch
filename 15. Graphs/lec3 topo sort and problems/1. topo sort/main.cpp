#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis, stack<int>& st) {
        vis[node] = 1;
        
        for(auto it: adj[node]) {
            if(!vis[it]) {
                dfs(it, adj, vis, st);
            }
        }
        st.push(node);
    }
    vector<int> topoSort(int v, vector<vector<int>> & adj) {
        stack<int> st;
        vector<int> vis(V, 0);
        vector<int> ans;

        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                dfs(i, adj, vis, st);
            }
        }

        while(!st.empty()) {
            ans.push_back(st.top());
            at.pop();
        }

        return ans;
    }
};

int main() {
    	//V = 6;
	vector<int> adj[6] = {{}, {}, {3}, {1}, {0, 1}, {0, 2}};
	int V = 6;
	Solution obj;
	vector<int> ans = obj.topoSort(V, adj);

	for (auto node : ans) {
		cout << node << " ";
	}
	cout << endl;

	return 0;
}