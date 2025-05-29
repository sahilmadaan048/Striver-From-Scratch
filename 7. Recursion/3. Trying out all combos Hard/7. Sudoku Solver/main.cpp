// https://leetcode.com/problems/sudoku-solver/description/

// https://takeuforward.org/data-structure/sudoku-solver/

// https://takeuforward.org/plus/dsa/problems/sudoko-solver

class Solution {
    bool isValid(int row, int col, vector<vector<char>>& board, char c) {
        for (int i = 0; i < 9; i++) {
            // Check row and column
            if (board[row][i] == c || board[i][col] == c)
                return false;

            // Check 3x3 sub-grid
            int boxRow = 3 * (row / 3) + i / 3;
            int boxCol = 3 * (col / 3) + i % 3;
            if (board[boxRow][boxCol] == c)
                return false;
        }
        return true;
    }

    bool solve(vector<vector<char>>& board) {
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                if (board[row][col] == '.') {
                    for (char c = '1'; c <= '9'; c++) {
                        if (isValid(row, col, board, c)) {
                            board[row][col] = c;
                            if (solve(board))
                                return true;
                            board[row][col] = '.'; // Backtrack
                        }
                    }
                    return false; // No valid number fits here
                }
            }
        }
        return true;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
