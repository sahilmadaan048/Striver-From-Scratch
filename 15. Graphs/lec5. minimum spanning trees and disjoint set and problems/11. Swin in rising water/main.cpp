// https://leetcode.com/problems/swim-in-rising-water/submissions/1747616871/


struct DSU {
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n+1);
        size.assign(n+1, 1);
        for(int i=0; i<=n; i++) parent[i]  = i ;
    }

    int find(int a) {
        if(a == parent[a]) return a;
        return parent[a] = find(parent[a]);
    }

    void unite(int a, int b) {
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
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int total = n * n;
        DSU dsu(total);

        vector<array<int,3>> cells;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cells.push_back({grid[i][j], i, j});
            }
        }

        sort(cells.begin(), cells.end());

        vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
        vector<vector<bool>> active(n, vector<bool>(n,false));

        for (auto &c : cells) {
            int h = c[0], i = c[1], j = c[2];
            int id = i * n + j;
            active[i][j] = true;

            for (auto &d : dirs) {
                int ni = i + d.first, nj = j + d.second;
                if (ni >= 0 && nj >= 0 && ni < n && nj < n && active[ni][nj]) {
                    dsu.unite(id, ni * n + nj);
                }
            }

            if (dsu.find(0) == dsu.find(total - 1)) {
                return h;
            }
        }
        return -1; 
    }
};