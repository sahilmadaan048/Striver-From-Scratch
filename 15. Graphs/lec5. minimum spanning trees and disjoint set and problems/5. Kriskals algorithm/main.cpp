// https://takeuforward.org/data-structure/kruskals-algorithm-minimum-spanning-tree-g-47/

#include <bits/stdc++.h>
using namespace std;

class DSU {
    vector<int> parent, size;

    public: 
    DSU(int n) {
        size.assign(n+1, 0);
        parent.resize(n+1);
        for(int i=0; i<=n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findPar(int node) {
        if(node == parent[node]) return node;
        return parent[node] = findPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        u = findPar(u);
        v = findPar(v);
  
        if(u != v) {
            if(size[u] < size[v]) {
                swap(u, v);
            }
            parent[v] = u;
            size[u] += size[v];
        }
    }
}; 


class Solution {
    public: 
    int spanningTree(int v,  vector<vector<int>> adj[]) {
        vector<pair<int, pair<int, int>>> edges;

        for(int i=0; i<v; i++) {
            for(auto it: adj[i]) {
                int adjNode = it[0];
                int wt = it[1];
                int node = i;

                edges.push_back({wt, {node, adjNode}});
            }
        }
        DSU ds(v);
        sort(edges.begin(), edges.end());

        int minWt = 0;
        for(auto it: edges) {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;

            if(ds.findPar(u) != ds.findPar(v)) {
                minWt += wt;
                ds.unionBySize(u, v);
            }
        }
        return minWt;
    } 
};


int main() {
   int V = 5;
    vector<vector<int>> edges = {{0, 1, 2}, {0, 2, 1}, {1, 2, 1}, {2, 3, 2}, {3, 4, 1}, {4, 2, 2}};
    vector<vector<int>> adj[V];
    for (auto it : edges) {
        vector<int> tmp(2);
        tmp[0] = it[1];
        tmp[1] = it[2];
        adj[it[0]].push_back(tmp);

        tmp[0] = it[0];
        tmp[1] = it[2];
        adj[it[1]].push_back(tmp);
    }

    Solution obj;
    int mstWt = obj.spanningTree(V, adj);
    cout << "The sum of all the edge weights: " << mstWt << endl;
    return 0;
}


/*

Output: The sum of all the edge weights: 5

Time Complexity: O(N+E) + O(E logE) + O(E*4α*2)   where N = no. of nodes and E = no. of edges. O(N+E) for extracting edge information from the adjacency list. O(E logE) for sorting the array consists of the edge tuples. Finally, we are using the disjoint set operations inside a loop. The loop will continue to E times. Inside that loop, there are two disjoint set operations like findUPar() and UnionBySize() each taking 4 and so it will result in 4*2. That is why the last term O(E*4*2) is added.

Space Complexity: O(N) + O(N) + O(E) where E = no. of edges and N = no. of nodes. O(E) space is taken by the array that we are using to store the edge information. And in the disjoint set data structure, we are using two N-sized arrays i.e. a parent and a size array (as we are using unionBySize() function otherwise, a rank array of the same size if unionByRank() is used) which result in the first two terms O(N).


*/