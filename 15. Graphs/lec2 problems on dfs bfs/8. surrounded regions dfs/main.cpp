// https://leetcode.com/problems/surrounded-regions/

class Solution {
public:
    void dfs(vector<vector<char>>& board, int row, int col) {

        board[row][col] = 'N';

        int r[] = {0, -1, 0, 1};
        int c[] = {-1, 0, 1, 0};

        for (int i = 0; i < 4; i++) {
            int nrow = row + r[i];
            int ncol = col + c[i];

            if (nrow >= 0 && nrow < board.size() && ncol >= 0 &&
                ncol < board[0].size() && board[nrow][ncol] == 'O') {
                dfs(board, nrow, ncol);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {

                if (i == 0 || i == board.size() - 1 || j == 0 ||
                    j == board[0].size() - 1) {

                    if (board[i][j] == 'O') {
                        dfs(board, i, j);
                    }
                }
            }
        }

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {

                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == 'N') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};

/*

Complexity Analysis

Time Complexity: O(N × M), since each cell is visited at most once during DFS and once during the final traversal.

Space Complexity: O(N × M), due to the visited matrix and the recursion stack in the worst case.

*/