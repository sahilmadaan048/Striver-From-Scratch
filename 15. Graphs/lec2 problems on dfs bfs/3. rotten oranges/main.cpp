// https://leetcode.com/problems/rotting-oranges/description/

// https://takeuforward.org/data-structure/rotten-oranges-min-time-to-rot-all-oranges-bfs/

class Solution {
    public:
        int orangesRotting(vector<vector<int>>& grid) {
            int n = grid.size();
            int m = grid[0].size();
            
            queue<pair<pair<int,int>, int>> q;
            vector<vector<int>> vis(n, vector<int>(m, 0));
            
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    if(grid[i][j] == 2) {
                        q.push({{i, j}, 0});
                        vis[i][j] = 2;
                    }
                }
            }
            
            int tm = 0;
            
            while(!q.empty()) {
                int r = q.front().first.first;
                int c = q.front().first.second;
                int t = q.front().second;
                q.pop();
                tm = max(tm, t);
                
                int delrow[] = {-1, 0, 1, 0};
                int delcol[] = {0, 1, 0, -1};
                
                for(int i = 0; i < 4; i++) {
                    int nrow = r + delrow[i];
                    int ncol = c + delcol[i];
                    
                    if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1 && vis[nrow][ncol] != 2) {
                        vis[nrow][ncol] = 2;
                        q.push({{nrow, ncol}, t + 1});
                    }
                }
            }
            
            // Check for any fresh oranges left
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    if(grid[i][j] == 1 && vis[i][j] != 2) {
                        return -1; // There are fresh oranges that couldn't be reached
                    }
                }
            }
            
            return tm;
        }
    };