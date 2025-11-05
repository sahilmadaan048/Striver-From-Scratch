// https://leetcode.com/problems/surrounded-regions/

class Solution 
{
public:
    int R, C;
    vector<vector<int>> visited;

    void dfs(int r, int c, vector<vector<char>>& board) {
        if(r < 0 or r > R-1 or c < 0 or c > C-1) return;

        if(board[r][c] == 'X') return;

        if(visited[r][c]) return;

        
        visited[r][c]=1;
        dfs(r+1 , c , board);
        dfs(r-1 , c, board);
        dfs(r ,c+1 , board);
        dfs(r , c-1 , board);

    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));

        R = m;
        C = n;
        visited = vis;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(i == 0 or i == m-1 or j == n-1 or j == 0 and board[i][j] == 'O') {
                    dfs(i, j, board);
                }
            }
        }

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(visited[i][j] == 0) {
                    board[i][j] = 'X';
                }
            }
        }

        return;
    }
};