// https://takeuforward.org/data-structure/number-of-operations-to-make-network-connected-dsu-g-49/

// https://leetcode.com/problems/number-of-operations-to-make-network-connected/description/


struct DSU {
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n+1);
        size.assign(n+1, 1);
        for(int i=0; i<=n; i++) parent[i] = i;
    }

    int find(int a) {
        if(a == parent[a]) return a;
        return parent[a] = find(parent[a]);
    }

    void union_set(int a, int b) {
        a = find(a);
        b = find(b);

        if(a != b) {
            if(size[a] < size[b]) {
                swap(a, b);
            }
            parent[b] = a;
            size[a] += size[b];
        }

        return;
    }
};


class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& temp) {
        // int n = temp.size();
        int sz = temp.size();

        DSU ds(n);

        int extra = 0;
        for(auto it: temp) {
            int u = it[0];
            int v = it[1];

            if(ds.find(u) == ds.find(v)) {
                extra++;
            }
            else {
                ds.union_set(u, v);
            }
        }

        int nc = 0;
        for(int i=0; i<n; i++) {
            if(ds.parent[i] == i) {
                nc++;
            }
        }

        if(extra >= (nc-1)) return (nc-1);
        return -1;
    }
};

