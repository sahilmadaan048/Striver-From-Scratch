// https://leetcode.com/problems/number-of-distinct-islands-ii/description/

// https://www.geeksforgeeks.org/problems/number-of-distinct-islands/1

// User function Template for C++

class Solution {
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    
    void dfs(int r, int c, int i, int j, vector<pair<int, int>>& islands, 
             int m, int n, vector<vector<int>>& grid, vector<vector<int>>& vis) {

        vis[i][j] = 1;
        islands.push_back({i - r, j - c}); 

        for (int k = 0; k < 4; k++) {
            int nrow = i + dx[k];
            int ncol = j + dy[k];

            if (nrow >= 0 && ncol >= 0 && nrow < m && ncol < n &&
                grid[nrow][ncol] == 1 && !vis[nrow][ncol]) {
                dfs(r, c, nrow, ncol, islands, m, n, grid, vis);
            }
        }
    }

public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        set<vector<pair<int, int>>> st;
        vector<vector<int>> vis(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    vector<pair<int, int>> island;
                    dfs(i, j, i, j, island, m, n, grid, vis);
                    st.insert(island);
                }
            }
        }

        return st.size();
    }
};
