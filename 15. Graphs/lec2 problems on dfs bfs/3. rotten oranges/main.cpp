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

/*

complexity analysis => 

time => o(n*n*4) in the worst case, every cell in the grid may contain an orange, and for each rotten orange we explore 4 directions
    - so we iterate through the cells n*n and oerform 4 operarions per oranfe, hence the complexity becomes
        - o(n*n*4) which simplifies to o(n^2)

space =>  o(n x n) => in the worst case, all the oranges might be rotten and will be stored on te queue siultaneously. the maximum size of the queue can be equa to the total
    number of oranges in the grid *n x n
    therefore the space complexity is o(n^2)
*/

