// https://leetcode.com/problems/number-of-enclaves/description/

class Solution {
public:
    int m, n;

    void dfs(int r, int c, vector<vector<int>>& grid) {
        if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == 0) return;

        grid[r][c] = 0;
        dfs(r + 1, c, grid);
        dfs(r - 1, c, grid);
        dfs(r, c + 1, grid);
        dfs(r, c - 1, grid);
    }

    int numEnclaves(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if ((i == 0 || j == 0 || i == m - 1 || j == n - 1) && grid[i][j] == 1) {
                    dfs(i, j, grid);
                }
            }
        }

        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) count++;
            }
        }

        return count;
    }
};
