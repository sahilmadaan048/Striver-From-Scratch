// https://takeuforward.org/data-structure/disjoint-set-union-by-rank-union-by-size-path-compression-g-46/


#include <bits/stdc++.h>
using namespace std;

class DSU {
    vector<int> rank, parent;

public: 
    DSU(int n) {
        rank.assign(n+1, 0);
        parent.resize(n+1);
        for(int i=0; i<=n; i++) parent[i] = i;
    }

    int findPar(int node) {
        if(node == parent[node]) return node;
        return parent[node] = findPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        u = findPar(u);
        v = findPar(v);
        if(u == v) return; // already in same set

        if (rank[u] < rank[v]) {
            swap(u, v);
        }
        parent[v] = u;

        if(rank[u] == rank[v]) {
            rank[u]++;
        }
    }
};

int main() {
    DSU ds(7);
    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);
    ds.unionByRank(5, 6);

    if (ds.findPar(3) == ds.findPar(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";

    ds.unionByRank(3, 7);

    if (ds.findPar(3) == ds.findPar(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";
    return 0;
}


/*

Output:

Not same
Same

Time Complexity:  The actual time complexity is O(4) which is very small and close to 1. So, we can consider 4 as a constant.

*/