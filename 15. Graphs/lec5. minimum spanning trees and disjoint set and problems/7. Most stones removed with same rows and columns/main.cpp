// https://takeuforward.org/data-structure/most-stones-removed-with-same-row-or-column-dsu-g-53/

// https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/description/

struct DSU {
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n);
        size.assign(n, 1);
        for(int i=0; i<n; i++) parent[i] = i;
    }

    int find(int a) {
        if(a == parent[a]) return a;
        return parent[a] = find(parent[a]);
    }

    void union_set(int a, int b) {
        a = find(a);
        b = find(b);
        if(a != b) {
            if(size[a] < size[b]) swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
    }
};


class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();

        int maxRow = 0;
        int maxCol = 0;
        for (auto it : stones) {
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }
        int total = maxRow + maxCol + 2;
        DSU dsu(total);
        unordered_set<int> nodesUsed;

        for(auto &it: stones) {
            int row = it[0];
            int col = it[1] + maxRow + 1; // offset column index

            dsu.union_set(row, col);

            nodesUsed.insert(row);
            nodesUsed.insert(col);
        }

        int components = 0;
        for(int node : nodesUsed) {
            if(dsu.find(node) == node) {
                components++;
            }
        }

        return n - components;
    }
};