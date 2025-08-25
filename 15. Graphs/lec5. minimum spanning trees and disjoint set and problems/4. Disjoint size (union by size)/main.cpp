// https://takeuforward.org/data-structure/disjoint-set-union-by-rank-union-by-size-path-compression-g-46/


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


int main() {
    DSU ds(7);
    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);

    if (ds.findPar(3) == ds.findPar(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";

    ds.unionBySize(3, 7);

    if (ds.findPar(3) == ds.findPar(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";
    return 0;
}