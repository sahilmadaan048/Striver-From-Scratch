// https://takeuforward.org/graph/number-of-islands-ii-online-queries-dsu-g-51/'

// https://takeuforward.org/plus/dsa/problems/number-of-islands-ii


struct DSU {
    vector<int> parent, size;
    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]); 
    }

    bool unite(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false;  
        if (size[a] < size[b]) swap(a, b);
        parent[b] = a;
        size[a] += size[b];
        return true;
    }
};

class Solution {
public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>>& operators) {
        DSU dsu(n*m);
        vector<int> ans;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int count = 0;
        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        for (auto &op : operators) {
            int r = op[0], c = op[1];
            if (vis[r][c]) {
                ans.push_back(count);
                continue;
            }
            vis[r][c] = 1;
            count++;
            int id1 = r*m + c;

            for (auto &d : dirs) {
                int nr = r + d[0], nc = c + d[1];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && vis[nr][nc]) {
                    int id2 = nr*m + nc;
                    if (dsu.unite(id1, id2)) {
                        count--;
                    }
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};


