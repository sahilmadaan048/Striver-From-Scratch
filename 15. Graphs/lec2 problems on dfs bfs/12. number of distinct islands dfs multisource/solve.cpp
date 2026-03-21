// https://leetcode.com/problems/number-of-islands/description/

// https://takeuforward.org/data-structure/number-of-distinct-islands


class Solution {
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    
    void dfs(int i, int j, int m, int n, 
             vector<vector<char>>& grid, vector<vector<int>>& vis) {

        vis[i][j] = 1;

        for (int k = 0; k < 4; k++) {
            int nrow = i + dx[k];
            int ncol = j + dy[k];

            if (nrow >= 0 && ncol >= 0 && nrow < m && ncol < n &&
                grid[nrow][ncol] == '1' && !vis[nrow][ncol]) {
                dfs(nrow, ncol, m, n, grid, vis);
            }
        }
    }
  
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));
        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && !vis[i][j]) {
                    count++; 
                    dfs(i, j, m, n, grid, vis);
                }
            }
        }

        return count;
    }
};

/*

Complexity Analysis

Time Complexity: O(N*M), DFS traversal and marking visited cells dominate.

Space Complexity: O(N*M), or visited grid and set storing unique island shapes.

*/