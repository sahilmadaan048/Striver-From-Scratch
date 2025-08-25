// https://takeuforward.org/data-structure/making-a-large-island-dsu-g-52/\


// https://leetcode.com/problems/making-a-large-island/description/



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
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();

        DSU dsu(n*n);

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 0) continue;

                int dx[4] = {-1,  0,  1, 0};
                int dy[4] = {0,  -1, 0, 1};

                for(int k=0; k<4; k++) {
                    int nrow = i + dx[k];
                    int ncol = j + dy[k];

                    if(nrow >=0 and nrow <n and ncol >=0 and ncol < n and grid[nrow][ncol] == 1) {
                        int u = i * n + j;
                        int v = nrow * n + ncol;

                        dsu.unite(u, v);
                    }
                }
            }
        }


        // lets go through the grid once again and now try out all zero elements and convert t hem to see the answer
        int maxi = 0;
        for(int row=0; row<n; row++) {
            for(int col = 0; col < n; col++) {  
                if(grid[row][col] == 1) continue;

                int dx[4] = {-1, 0, 1, 0};
                int dy[4] = {0, -1, 0, 1};

                set<int> st;

                for(int i=0; i<4; i++) {
                    int nrow = row + dx[i];
                    int ncol = col + dy[i];


                    if(nrow >=0 and ncol >=0 and nrow < n and ncol < n) {
                        if(grid[nrow][ncol] == 1) {
                            int node = nrow * n + ncol;
                            st.insert(dsu.find(node));
                        }
                    }

                    int total = 0;
                    for(auto it: st) {
                        total += dsu.size[dsu.find(it)];
                    }

                    maxi = max(maxi, total + 1);
                }
            }
        }

        for(int node = 0; node<n*n; node++) {
            if(dsu.find(node) == node) {
                maxi = max(maxi, dsu.size[node]);
            }
        }

        return maxi;
    }
};